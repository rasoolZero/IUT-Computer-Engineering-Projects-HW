
--- function to calculate average user rating score of an album
go
create or alter function album_avg_score(@album_ID int)
returns float
as begin
	declare @avgscore float;
	select @avgscore = avg(score) from [user_rating] join [album_music] 
	on (user_rating.music_ID = album_music.music_ID)
	where album_music.album_ID = @album_ID;
	return @avgscore;
end;


--- function to calculate average user rating score of a playlist
go
create or alter function playlist_avg_score(@playlist_ID int)
returns float
as begin
	declare @avgscore float;
	select @avgscore = avg(score) from [user_rating] join [playlist_music] 
	on (user_rating.music_ID = playlist_music.music_ID)
	where playlist_music.playlist_ID = @playlist_ID;
	return @avgscore;
end;


--- function to calculate average user rating score of an artist
go
create or alter function artist_avg_score(@artist_ID int)
returns float
as begin
	declare @avgscore float;
	select @avgscore = avg(score) from user_rating as UR join music as M on (UR.music_ID = M.ID)
	left join additional_artists as AA on (M.ID = AA.music_ID)
	where M.artist_ID = @artist_ID OR AA.artist_ID = @artist_ID;
	return @avgscore;
end;

--- function to calculate average user rating score of an artist
go
create or alter function music_avg_score(@music_ID int)
returns float
as begin
	declare @avgscore float;
	select @avgscore = avg(score) from user_rating  as UR
	where UR.music_ID = @music_ID;
	return @avgscore;
end;







--- procedure to ban a user (removing all the ratings and also changing the text of their comments to [deleted by admin])
go
create or alter procedure ban_user
@user_id int
as begin
	update comment set [text] = '[deleted by admin]' where user_ID = @user_ID;
	delete user_rating where user_ID = @user_ID;
end;
---execute dbo.ban_user @user_ID = 1;

--- procedure to check if an email address is correct
go
CREATE or alter procedure dbo.ChkValidEmail 
	@EMAIL varchar(100),
	@ResultBit int output
as
BEGIN     
  DECLARE @bitEmailVal as Bit
  DECLARE @EmailText varchar(100)

  SET @EmailText=ltrim(rtrim(isnull(@EMAIL,'')))

  SET @ResultBit = case when @EmailText = '' then 0
                          when @EmailText like '% %' then 0
                          when @EmailText like ('%["(),:;<>\]%') then 0
                          when substring(@EmailText,charindex('@',@EmailText),len(@EmailText)) like ('%[!#$%&*+/=?^`_{|]%') then 0
                          when (left(@EmailText,1) like ('[-_.+]') or right(@EmailText,1) like ('[-_.+]')) then 0                                                                                    
                          when (@EmailText like '%[%' or @EmailText like '%]%') then 0
                          when @EmailText LIKE '%@%@%' then 0
                          when @EmailText NOT LIKE '_%@_%._%' then 0
                          else 1 
                      end
END;
--go
--declare @result int
--execute dbo.ChkValidEmail "rasool@gmail.com",@ResultBit= @result output;
--select @result;



--- procedure to remove all empty albums and playlists (can be used periodicly)
go
create or alter procedure PurgeAlbumsAndPlaylists as begin
delete from playlist where ID not in (select distinct(playlist_ID) from playlist_music)
delete from album where ID not in (select distinct(album_ID) from album_music)
end;







--view for getting top 10 rated musics and the artist name
go
create or alter view top_ten_rated_musics as
select top 10  M.[name] as 'Music Name',A.username as 'Artist',dbo.music_avg_score(M.ID) as 'average music score' 
from music as M join artist as A on(M.artist_ID = A.ID)
order by 'average music score' desc;

--view for getting top 3 rated albums and the artist name and publisher
go
create or alter view top_three_rated_albums as
select top 3  Al.[name] as 'Album Name',Ar.username as 'Artist',P.name as 'Publisher',dbo.album_avg_score(Al.ID) as 'average album score' 
from album as Al join artist as Ar on(Al.artist_ID = Ar.ID)
join publisher as P on (Al.publisher_ID = P.ID)
order by 'average album score' desc;

--view for getting top 3 rated artists and their top music
go
create or alter view top_three_rated_artists as
select top 3 A.username,dbo.artist_avg_score(A.ID) as 'average artist score',M.name as "the artist's top music"
from artist as A join music as M on (M.artist_ID = A.ID)
where M.ID in (select top 1 ID from music where artist_ID = A.ID order by dbo.music_avg_score(id) DESC )
order by 'average artist score' desc;







--trigger to check if email address inserted or updated to table user is corecct
go
create or alter trigger checkemailuser on [user] after update,insert
as begin
	SET NOCOUNT ON;
	declare @email varchar(255);
	declare @isValid int;
	select @email = email from inserted;
	exec dbo.ChkValidEmail @email,@ResultBit = @isValid output;
	if @isValid = 0
		begin
			print concat('invalid email : ',@email);
			rollback transaction
		end
end;
--go
--update [user] set email = 'Frances_Legros' where ID = 1;
---Frances_Legros@hotmail.com

--trigger to check if email address inserted or updated to table artist is corecct
go
create or alter trigger checkemailartist on artist after update,insert
as begin
	SET NOCOUNT ON;
	declare @email varchar(255);
	declare @isValid int;
	select @email = email from inserted;
	exec dbo.ChkValidEmail @email,@ResultBit = @isValid output;
	if @isValid = 0
		begin
			print concat('invalid email : ',@email);
			rollback transaction
		end
end;


--trigger to check if email address inserted or updated to table publisher is corecct
go
create or alter trigger checkemailpublisher on publisher after update,insert
as begin
	SET NOCOUNT ON;
	declare @email varchar(255);
	declare @isValid int;
	select @email = email from inserted;
	exec dbo.ChkValidEmail @email,@ResultBit = @isValid output;
	if @isValid = 0
		begin
			print concat('invalid email : ',@email);
			rollback transaction
		end
end;

------- برخی دستورات آموزش داده شده در فایل مربوط به توابع و پروسیجر ها قرار دارند -------


--- union example : selecting all users and artists firstname and lastname
go
select first_name,last_name  , 'user' as type from [user]
union all
select first_name,last_name , 'artist' from artist;



--- ranking artists based on average score
go
select ID,first_name,last_name,username, dbo.artist_avg_score(ID) as 'artist avg score', 
DENSE_RANK() over (order by dbo.artist_avg_score(ID) desc) as 'rank'
from artist
order by  last_name,first_name;


--- windowing example : total comments for each publisher per music
go
select publisher.ID as 'publisher ID' ,music.ID as 'music ID',count(comment.ID) over (partition by publisher.ID, music.ID) as 'total comments per music'
from comment join music on(comment.music_ID = music.ID)
join publisher on (music.publisher_ID = publisher.ID)
order by publisher.ID;


--- 
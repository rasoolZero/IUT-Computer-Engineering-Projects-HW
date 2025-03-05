CREATE TABLE [additional_artists] (
  [music_ID] int NOT NULL,
  [artist_ID] int NOT NULL,
  PRIMARY KEY CLUSTERED ([music_ID], [artist_ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [album] (
  [ID] int NOT NULL,
  [name] varchar(255) NOT NULL,
  [artist_ID] int NOT NULL,
  [publisher_ID] int NULL,
  [registration_date] datetime2 NOT NULL,
  [creation_date] datetime2 NULL,
  PRIMARY KEY CLUSTERED ([ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [album_music] (
  [album_ID] int NOT NULL,
  [music_ID] int NOT NULL,
  PRIMARY KEY CLUSTERED ([album_ID], [music_ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [artist] (
  [ID] int NOT NULL,
  [first_name] varchar(255) NOT NULL,
  [last_name] varchar(255) NULL,
  [username] varchar(255) NOT NULL,
  [email] varchar(255) NULL,
  [phone_number] varchar(20) NULL,
  [birth_date] datetime2 NULL,
  [creation_date] datetime2 NOT NULL,
  PRIMARY KEY CLUSTERED ([ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [comment] (
  [ID] int NOT NULL,
  [user_ID] int NOT NULL,
  [music_ID] int NOT NULL,
  [text] varchar(511) NOT NULL,
  PRIMARY KEY CLUSTERED ([ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [music] (
  [ID] int NOT NULL,
  [name] varchar(255) NOT NULL,
  [artist_ID] int NOT NULL,
  [registration_date] datetime2 NOT NULL,
  [creation_date] datetime2 NOT NULL,
  [publisher_ID] int NOT NULL,
  PRIMARY KEY CLUSTERED ([ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [playlist] (
  [ID] int NOT NULL,
  [user_ID] int NOT NULL,
  [name] varchar(255) NOT NULL,
  PRIMARY KEY CLUSTERED ([ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [playlist_music] (
  [playlist_ID] int NOT NULL,
  [music_ID] int NOT NULL,
  PRIMARY KEY CLUSTERED ([playlist_ID], [music_ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [publisher] (
  [ID] int NOT NULL,
  [name] varchar(255) NOT NULL,
  [address] varchar(511) NULL,
  [contact_number] varchar(20) NULL,
  [registration_date] datetime2 NOT NULL,
  [email] varchar(255) NOT NULL,
  PRIMARY KEY CLUSTERED ([ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [user] (
  [ID] int NOT NULL,
  [first_name] varchar(255) NULL,
  [last_name] varchar(255) NULL,
  [username] varchar(255) NOT NULL,
  [email] varchar(255) NOT NULL,
  PRIMARY KEY CLUSTERED ([ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

CREATE TABLE [user_rating] (
  [user_ID] int NOT NULL,
  [music_ID] int NOT NULL,
  [score] float NOT NULL,
  PRIMARY KEY CLUSTERED ([user_ID], [music_ID])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)
)
GO

ALTER TABLE [additional_artists] ADD CONSTRAINT [fk_additional_artists_artist_1] FOREIGN KEY ([artist_ID]) REFERENCES [artist] ([ID])
GO
ALTER TABLE [additional_artists] ADD CONSTRAINT [fk_additional_artists_music_1] FOREIGN KEY ([music_ID]) REFERENCES [music] ([ID])
GO
ALTER TABLE [album] ADD CONSTRAINT [fk_album_artist_1] FOREIGN KEY ([artist_ID]) REFERENCES [artist] ([ID])
GO
ALTER TABLE [album] ADD CONSTRAINT [fk_album_publisher_1] FOREIGN KEY ([publisher_ID]) REFERENCES [publisher] ([ID])
GO
ALTER TABLE [album_music] ADD CONSTRAINT [fk_album_music_album_1] FOREIGN KEY ([album_ID]) REFERENCES [album] ([ID])
GO
ALTER TABLE [album_music] ADD CONSTRAINT [fk_album_music_music_1] FOREIGN KEY ([music_ID]) REFERENCES [music] ([ID])
GO
ALTER TABLE [comment] ADD CONSTRAINT [fk_comment_user_1] FOREIGN KEY ([user_ID]) REFERENCES [user] ([ID])
GO
ALTER TABLE [comment] ADD CONSTRAINT [fk_comment_music_1] FOREIGN KEY ([music_ID]) REFERENCES [music] ([ID])
GO
ALTER TABLE [music] ADD CONSTRAINT [fk_music_artist_1] FOREIGN KEY ([artist_ID]) REFERENCES [artist] ([ID])
GO
ALTER TABLE [music] ADD CONSTRAINT [fk_music_publisher_1] FOREIGN KEY ([publisher_ID]) REFERENCES [publisher] ([ID])
GO
ALTER TABLE [playlist] ADD CONSTRAINT [fk_playlist_user_1] FOREIGN KEY ([user_ID]) REFERENCES [user] ([ID])
GO
ALTER TABLE [playlist_music] ADD CONSTRAINT [fk_playlist_music_playlist_1] FOREIGN KEY ([playlist_ID]) REFERENCES [playlist] ([ID])
GO
ALTER TABLE [playlist_music] ADD CONSTRAINT [fk_playlist_music_music_1] FOREIGN KEY ([music_ID]) REFERENCES [music] ([ID])
GO
ALTER TABLE [user_rating] ADD CONSTRAINT [fk_user_rating_user_1] FOREIGN KEY ([user_ID]) REFERENCES [user] ([ID])
GO
ALTER TABLE [user_rating] ADD CONSTRAINT [fk_user_rating_music_1] FOREIGN KEY ([music_ID]) REFERENCES [music] ([ID])
GO


CREATE TABLE `products` (
  `id` bigint NOT NULL AUTO_INCREMENT PRIMARY KEY,
  `name` varchar(255) NOT NULL,
  `price` DECIMAL(10,2) NOT NULL,
  `show` boolean NOT NULL DEFAULT 1
);


INSERT INTO `products` (`name`, `price` ,`show`) VALUES
('Gold-plated Spear Chain Necklace',2962.30, 0),
('EQUESTRIAN JEWELRY - PARIS BRACELET | "ROSE GOLD"',490.75, 1),
('Kindrea ring, set with cut-down diamonds',1092.50, 0),
('Gucci Silver bracelet with Interlocking G',290.00, 1),
('Ananda Soul - Sun & Moon Necklace',306.00 , 1),
('Aphrodite Ring with 0.32 Carat Round Diamond', 1803.74, 0),
('AMONG THE STARS NECKLACE',332.00 , 1),
('HERE TO BE EARRINGS',215.00 , 1),
('Gold-plated Pavé Spear Chain Necklace',6051.48, 0),
('Gold-plated Hollow Medallion Necklace',1592.63 , 0);
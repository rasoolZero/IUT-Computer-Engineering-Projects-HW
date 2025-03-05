CREATE TABLE "games" (
  "game_id" serial PRIMARY KEY,
  "game_name" varchar(250),
  "price" decimal(6,2),
  "min_memory_size" int2,
  "is_online" bool,
  "max_no_players" int2,
  "details" varchar(250)
);

CREATE TABLE "game_tags" (
  "game_id" int4,
  "tag_id" int4,
  PRIMARY KEY ("game_id", "tag_id")
);

CREATE TABLE "tags" (
  "tag_id" serial PRIMARY KEY,
  "tag_name" varchar(100)
);

CREATE TABLE "users" (
  "user_id" serial PRIMARY KEY,
  "username" varchar(100) UNIQUE,
  "password" varchar(100),
  "email_address" varchar(150),
  "first_name" varchar(150),
  "last_name" varchar(150),
  "birth_date" date,
  "country_code" varchar(2)
);

CREATE TABLE "order_games" (
  "order_id" int4,
  "game_id" int4,
  "game_price" decimal(6,2),
  "price_after_discount" decimal(6,2),
  PRIMARY KEY ("order_id", "game_id")
);

CREATE TABLE "orders" (
  "order_id" serial PRIMARY KEY,
  "user_id" int4,
  "order_date" date,
  "order_status" varchar(50),
  "coupon_code" varchar(50)
);

CREATE TABLE "coupons" (
  "coupon_code" varchar(50) PRIMARY KEY,
  "coupon_effective_until" date,
  "coupon_discount" decimal(4,2)
);

CREATE TABLE "reviews" (
  "game_id" int4,
  "user_id" int4,
  "review_date" date,
  "rating" decimal(2,1),
  "review_text" text,
  "recommend" bool,
  PRIMARY KEY ("game_id", "user_id")
);

CREATE TABLE "countries" (
  "country_code" varchar(2) PRIMARY KEY,
  "country_name" varchar(70)
);


ALTER TABLE "order_games" ADD FOREIGN KEY ("game_id") REFERENCES "games" ("game_id");
ALTER TABLE "order_games" ADD FOREIGN KEY ("order_id") REFERENCES "orders" ("order_id");

ALTER TABLE "game_tags" ADD FOREIGN KEY ("game_id") REFERENCES "games" ("game_id");
ALTER TABLE "game_tags" ADD FOREIGN KEY ("tag_id") REFERENCES "tags" ("tag_id");

ALTER TABLE "orders" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id");

ALTER TABLE "reviews" ADD FOREIGN KEY ("game_id") REFERENCES "games" ("game_id");
ALTER TABLE "reviews" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id");

ALTER TABLE "users" ADD FOREIGN KEY ("country_code") REFERENCES "countries" ("country_code");

ALTER TABLE "orders" ADD FOREIGN KEY ("coupon_code") REFERENCES "coupons" ("coupon_code");

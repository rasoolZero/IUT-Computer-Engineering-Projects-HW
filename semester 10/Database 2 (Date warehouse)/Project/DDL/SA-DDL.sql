CREATE TABLE "games" (
  "game_id" serial PRIMARY KEY,
  "game_name" varchar(350),
  "price" decimal(8,2),
  "min_memory_size" int2,
  "is_online" bool,
  "max_no_players" int2,
  "details" varchar(350)
);


CREATE TABLE "users" (
  "user_id" serial PRIMARY KEY,
  "email_address" varchar(200),
  "first_name" varchar(200),
  "last_name" varchar(200),
  "birth_date" date,
  "country_code" varchar(2)
);

CREATE TABLE "order_games" (
  "order_id" int4,
  "game_id" int4,
  "game_price" decimal(8,2),
  "price_after_discount" decimal(8,2),
  PRIMARY KEY ("order_id", "game_id")
);

CREATE TABLE "orders" (
  "order_id" serial PRIMARY KEY,
  "user_id" int4,
  "order_date" date,
  "order_status" varchar(70),
  "coupon_code" varchar(70)
);

CREATE TABLE "coupons" (
  "coupon_code" varchar(70) PRIMARY KEY,
  "coupon_effective_until" date,
  "coupon_discount" decimal(6,3)
);

CREATE TABLE "countries" (
  "country_code" varchar(2) PRIMARY KEY,
  "country_name" varchar(70)
);


ALTER TABLE "order_games" ADD FOREIGN KEY ("game_id") REFERENCES "games" ("game_id");
ALTER TABLE "order_games" ADD FOREIGN KEY ("order_id") REFERENCES "orders" ("order_id");

ALTER TABLE "orders" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id");

ALTER TABLE "users" ADD FOREIGN KEY ("country_code") REFERENCES "countries" ("country_code");

ALTER TABLE "orders" ADD FOREIGN KEY ("coupon_code") REFERENCES "coupons" ("coupon_code");

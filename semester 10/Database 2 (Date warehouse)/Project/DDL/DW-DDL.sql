CREATE TABLE "date_dim" (
  "time_key" int4 PRIMARY KEY,
  "full_date_alternate_key" date UNIQUE,
  "day_number_of_week" int4,
  "english_day_name_of_week" varchar(30),
  "day_number_of_month" int4,
  "day_number_of_year" int4,
  "week_number_of_year" int4,
  "english_month_name" varchar(10),
  "month_number_of_year" int4
);

CREATE TABLE "orders_dim_scd1" (
  "order_id" int4 PRIMARY KEY,
  "coupon_code" varchar(70),
  "coupon_effective_until" date,
  "coupon_discount" decimal(6,3),
  "order_status" varchar(70)
);

CREATE TABLE "game_dim_scd2" (
  "game_key" serial PRIMARY KEY,
  "game_id" int4,
  "game_name" varchar(350),
  "min_memory_size" int2,
  "is_online" bool,
  "max_no_players" int2,
  "details" varchar(350),
  "price" decimal(8,2),
  "price_start_date" date,
  "price_end_date" date,
  "price_current_flag" bool
);

CREATE TABLE "users_dim_scd3" (
  "user_id" int4 PRIMARY KEY,
  "email_address" varchar(200),
  "first_name" varchar(200),
  "last_name" varchar(200),
  "birth_date" date,
  "original_country_code" varchar(2),
  "original_country_name" varchar(70),
  "original_effective_until" date,
  "previous_country_code" varchar(2),
  "previous_country_name" varchar(70),
  "previous_effective_until" date,
  "current_country_code" varchar(2),
  "current_country_name" varchar(70)
);

CREATE TABLE "fact_orders_transactional" (
  "order_id" int4,
  "user_id" int4,
  "game_key" int4,
  "time_key" int4,
  "game_price" decimal(8,2),
  "game_price_after_discount" decimal(8,2),
  "cheapest_game_price" decimal(8,2),
  "expensive_game_price" decimal(8,2),
  "games_count" int4
);

CREATE TABLE "fact_orders_periodic_monthly" (
  "user_id" int4,
  "time_key" int4,
  "cheapest_game_price" decimal(8,2),
  "expensive_game_price" decimal(8,2),
  "average_game_price" decimal(10,2),
  "total_game_price" decimal(12,2),
  "number_of_orders" int4,
  "total_games_bought" int4
);

CREATE TABLE "fact_orders_acc" (
  "user_id" int4,
  "cheapest_game_price" decimal(8,2),
  "expensive_game_price" decimal(8,2),
  "average_game_price" decimal(10,2),
  "total_game_price" decimal(12,2),
  "number_of_orders" int4,
  "total_games_bought" int4
);

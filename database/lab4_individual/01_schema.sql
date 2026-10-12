-- ЛР №4. Дополнительные атрибуты варианта «Деятельность стола заказов».
-- Выполнить один раз в базе lab1_db.
-- Значения существующих строк остаются NULL, пока вы их не заполните.
ALTER TABLE "Client"
    ADD COLUMN IF NOT EXISTS city varchar(100),
    ADD COLUMN IF NOT EXISTS credit numeric(12,2);

ALTER TABLE "Order"
    ADD COLUMN IF NOT EXISTS completion_date date,
    ADD COLUMN IF NOT EXISTS discount_percent numeric(5,2) DEFAULT 0;

-- Проверка, какие данные предстоит заполнить.
SELECT client_id, name, city, credit FROM "Client" ORDER BY client_id;
SELECT order_id, order_date, completion_date, discount_percent FROM "Order" ORDER BY order_id;
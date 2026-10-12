-- Индивидуальные задания ЛР №4 (PostgreSQL, lab1_db).
-- Сначала выполнить 01_schema.sql и заполнить новые поля.
-- 1. Заказ, на выполнение которого ушло больше всего дней.
SELECT o.order_id AS "Номер заказа",
       o.order_date AS "Дата получения",
       o.completion_date AS "Дата выполнения",
       o.completion_date - o.order_date AS "Дней выполнения"
FROM "Order" o
WHERE o.completion_date IS NOT NULL
  AND o.order_date IS NOT NULL
  AND o.completion_date >= o.order_date
  AND o.completion_date - o.order_date = (
      SELECT MAX(completion_date - order_date)
      FROM "Order"
      WHERE completion_date IS NOT NULL
        AND order_date IS NOT NULL
        AND completion_date >= order_date
  );

-- 2. Клиенты, у которых стоимость хотя бы одного заказа больше кредита.
SELECT c.name AS "Клиент",
       o.order_id AS "Номер заказа",
       c.credit AS "Кредит",
       SUM(p.price * oi.quantity) AS "Стоимость заказа"
FROM "Client" c
JOIN "Order" o ON o.client_id = c.client_id
JOIN "Order_item" oi ON oi.order_id = o.order_id
JOIN "Product" p ON p.product_id = oi.product_id
WHERE c.credit IS NOT NULL
GROUP BY c.client_id, c.name, c.credit, o.order_id
HAVING SUM(p.price * oi.quantity) > c.credit;

-- 3. Стоимость каждого заказа с учётом скидки (%).
SELECT o.order_id AS "Номер заказа",
       COALESCE(SUM(p.price * oi.quantity), 0) AS "Стоимость до скидки",
       COALESCE(o.discount_percent, 0) AS "Скидка, %",
       ROUND(COALESCE(SUM(p.price * oi.quantity), 0) *
             (1 - COALESCE(o.discount_percent, 0) / 100.0), 2) AS "Стоимость со скидкой"
FROM "Order" o
LEFT JOIN "Order_item" oi ON oi.order_id = o.order_id
LEFT JOIN "Product" p ON p.product_id = oi.product_id
GROUP BY o.order_id, o.discount_percent
ORDER BY o.order_id;

-- 4. Клиент, купивший больше всего единиц товаров.
WITH purchases AS (
    SELECT c.client_id, c.name, SUM(oi.quantity) AS total_quantity
    FROM "Client" c
    JOIN "Order" o ON o.client_id = c.client_id
    JOIN "Order_item" oi ON oi.order_id = o.order_id
    GROUP BY c.client_id, c.name
)
SELECT name AS "Клиент", total_quantity AS "Куплено товаров"
FROM purchases
WHERE total_quantity = (SELECT MAX(total_quantity) FROM purchases);

-- 5. Город клиента, который оформил больше всего заказов.
WITH client_orders AS (
    SELECT c.client_id, c.name, c.city, COUNT(o.order_id) AS order_count
    FROM "Client" c
    JOIN "Order" o ON o.client_id = c.client_id
    WHERE c.city IS NOT NULL
    GROUP BY c.client_id, c.name, c.city
)
SELECT name AS "Клиент", city AS "Город", order_count AS "Количество заказов"
FROM client_orders
WHERE order_count = (SELECT MAX(order_count) FROM client_orders);
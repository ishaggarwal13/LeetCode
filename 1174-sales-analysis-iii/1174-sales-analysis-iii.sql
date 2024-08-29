# Write your MySQL query statement below
SELECT product_id, product_name
FROM product
natural JOIN sales
group by product_id
having min(sale_date) >= '2019-01-01' and max(sale_date) <= '2019-03-31';

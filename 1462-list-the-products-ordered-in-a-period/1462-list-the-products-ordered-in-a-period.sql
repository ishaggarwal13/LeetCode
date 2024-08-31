# Write your MySQL query statement below
select p.product_name, sum(o.unit) as unit
from products as p
join orders as o
#using(product_id) 
on p.product_id = o.product_id
where year(o.order_date) = '2020' and month(o.order_date) = '02'
group by p.product_id
having sum(o.unit) >= 100
# Write your MySQL query statement below
select product_id,product_name
from product p join sales s 
using(product_id)
group by product_id
having sum(sale_date<"2019-01-01")=0
and sum(sale_date>"2019-03-31")=0

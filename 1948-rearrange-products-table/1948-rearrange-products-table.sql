/* Write your T-SQL query statement below */
select product_id, store, price
from products
UNPIVOT(
    price
    for store in (store1, store2, store3)
) as tmp
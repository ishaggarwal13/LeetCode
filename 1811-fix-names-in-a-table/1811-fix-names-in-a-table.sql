# Write your MySQL query statement below
#use concat the string of first char left and rest as right in upper and lower case
#left(column name, no of charcters) and right(column name, no of chracters)
select user_id, concat(upper(left(name, 1)), lower(right(name, length(name)-1))) as name
from users
order by user_id
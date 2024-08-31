# Write your MySQL query statement below
#use concat the string of first char as upper and rest as lower using substr
#substr(string_name, start index, end index)
select user_id, concat(upper(substr(name, 1, 1)), lower(substr(name, 2, length(name)))) as name
from users
order by user_id
# Write your MySQL query statement below
SELECT * 
from users
where REGEXP_like (mail, '^[A-Za-z][A-Za-z0-9_.-]*@leetcode[.]com$');
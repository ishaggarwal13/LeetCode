# Write your MySQL query statement below
select * from patients
where REGEXP_LIKE(conditions, '\\bDIAB1'); 
#\b matches either a non-word character (in our case, a space) 
#or the position before the first character in the string
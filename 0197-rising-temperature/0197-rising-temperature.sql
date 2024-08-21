# Write your MySQL query statement below
select y.id from weather x, weather y
where datediff(y.recorddate, x.recorddate) = 1 and x.temperature < y.temperature;
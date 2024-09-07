# Write your MySQL query statement below
select s.score, count(s2.score) as `Rank` from 
       (select distinct score from scores) s2  ,
        scores s 
    where s.score<= s2.score

group by s.id
order by s.score desc;
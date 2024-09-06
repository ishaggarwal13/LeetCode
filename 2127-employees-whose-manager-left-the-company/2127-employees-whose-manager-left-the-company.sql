# Write your MySQL query statement below
select e1.employee_id
from employees e1
left join employees e2
ON e1.manager_id = e2.employee_id
WHERE e1.salary < 30000 AND e2.employee_id IS NULL AND e1.manager_id IS NOT NULL
order by employee_id;
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    SELECT DISTINCT Salary
    FROM Employee e1
    WHERE N-1 = (SELECT COUNT(DISTINCT Salary) FROM Employee e2 WHERE e1.Salary < e2.Salary)
  );
END
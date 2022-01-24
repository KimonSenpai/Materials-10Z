
SELECT C.name, city, comments, E.first_name, E.last_name, credit_limit
	FROM CUSTOMER AS C LEFT OUTER JOIN EMPLOYEE AS E ON C.salesperson_id = E.employee_id
	WHERE credit_limit >= 5000


SELECT *
	FROM CUSTOMER AS C LEFT OUTER JOIN EMPLOYEE AS E ON C.salesperson_id = E.employee_id
	ORDER BY C.name ASC


SELECT city, SUM(credit_limit) AS credit_sum
	FROM CUSTOMER
	GROUP BY city
	ORDER BY city

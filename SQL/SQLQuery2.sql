--Выбрать значения задержки поставки товара после заказа для всех покупателей, живущих в штате 'CA' (Калифорния)
--Выбрать названия и города тех отделов, у которых нет начальников (должность - 'MANAGER')
--Выбрать даты и имена покупателей тех заказов, которые обслуживал продавец 'SMITH' и в которых сумма заказа превышала кредит покупателя.
--Выбрать названия продукта, для которого в 1991 г. было продано минимальное количество экземпляров продукта.

--DDL - data declation lenguage (CREATE, ALTER, DROP, GRANT)
--DML - data manipulation lenguage (SELECT, INSERT, UPDATE, DELETE)


SELECT SO.order_id, C.name, DATEDIFF(DAY, SO.order_date, SO.ship_date) AS Delay
	FROM SALES_ORDER AS SO INNER JOIN CUSTOMER AS C ON SO.customer_id = C.customer_id
	WHERE C.state = 'CA'


SELECT D.NAME, L.regional_group
	FROM (SELECT E.employee_id, E.department_id
			FROM EMPLOYEE AS E INNER JOIN JOB AS J ON E.job_id = J.job_id
			WHERE J.[function] = 'MANAGER') AS S
			RIGHT OUTER JOIN DEPARTMENT AS D ON S.department_id = D.department_id
			INNER JOIN LOCATION AS L ON D.location_id = L.location_id
	WHERE S.employee_id IS NULL
		
--ISNULL(S.employee_id, -1) = -1
SELECT TOP 1 P.description
	FROM PRODUCT AS P INNER JOIN ITEM AS I ON P.product_id = I.product_id
		INNER JOIN SALES_ORDER AS SO ON I.order_id = SO.order_id
	WHERE YEAR(SO.order_date) = 1991
	GROUP BY P.product_id, P.description
	ORDER BY SUM(I.quantity) ASC

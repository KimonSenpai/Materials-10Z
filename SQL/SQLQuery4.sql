CREATE VIEW NoManager AS
	SELECT D.NAME, L.regional_group
	FROM (SELECT E.employee_id, E.department_id
			FROM EMPLOYEE AS E INNER JOIN JOB AS J ON E.job_id = J.job_id
			WHERE J.[function] = 'MANAGER') AS S
			RIGHT OUTER JOIN DEPARTMENT AS D ON S.department_id = D.department_id
			INNER JOIN LOCATION AS L ON D.location_id = L.location_id
	WHERE S.employee_id IS NULL
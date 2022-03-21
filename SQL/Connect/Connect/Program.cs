using System;
using System.Data.SqlClient;
using System.Data.SqlTypes;

namespace MyApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        const string connectionString =
            "Server=CHOMSKY\\SQLEXPRESS;Database=King_corporation;User Id=sa;Password=1;";
        static void Main(string[] args)
        {
            var connection = new SqlConnection(connectionString);

            connection.Open();

            var command = new SqlCommand(@"SELECT C.name, city, comments, E.first_name, E.last_name, credit_limit
                FROM CUSTOMER AS C LEFT OUTER JOIN EMPLOYEE AS E ON C.salesperson_id = E.employee_id
                WHERE credit_limit >= @limit", connection);
            //command.
            var reader = command.ExecuteReader();

            if (reader.HasRows) // если есть данные
            {
                
                // выводим названия столбцов
                Console.WriteLine("{0}\t{1}\t{2}", reader.GetName(0), reader.GetName(1), reader.GetName(2));

                while (reader.Read()) // построчно считываем данные
                {
                    object id = reader.GetValue(0);
                    object name = reader.GetValue(1);
                    object age = reader.GetValue(2);

                    Console.WriteLine("{0} \t{1} \t{2}", id, name, age);
                }
            }


            connection.Close();
        }
    }
}
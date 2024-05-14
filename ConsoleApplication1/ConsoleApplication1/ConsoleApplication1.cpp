#include <iostream>
#include "../../../MySQL Connector C++ 8.4/include/jdbc/cppconn/callback.h"
#include "../../../MySQL Connector C++ 8.4/include/jdbc/mysql_connection.h"
#include "../../../MySQL Connector C++ 8.4/include/jdbc/mysql_driver.h"
#include "../../../MySQL Connector C++ 8.4/include/jdbc/cppconn/statement.h"


using namespace std;

int main() {
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;


        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("85.193.89.100:3306", "arduino", "sRYdkp!cftI8MmN8");

        con->setSchema("beez");

        sql::Statement* stmt;
        sql::ResultSet* res;

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM dt");

        while (res->next()) {
            int id = res->getInt("id");
            float weight = static_cast<float>(res->getDouble("weight"));
            float humidity = static_cast<float>(res->getDouble("humidity"));
            float temperature = static_cast<float>(res->getDouble("temperature"));
        }


        delete res;
        delete stmt;

        delete con; // Закрываем соединение

    }
    catch (sql::SQLException& e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return 0;
}
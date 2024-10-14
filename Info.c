#include <stdio.h>
#include <mysql/mysql.h> 
#define MAX 100

int main(int argc, char *argv[]) {
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "mysql";
	char *database = "Info"; 


char query[MAX];
	char activity[MAX];
	
	conn = mysql_init(NULL);
	
	printf("Enter activity (Yoga, Dance or Library: ");
	scanf("%s", activity);

sprintf(query, "SELECT User.Name FROM User, Participant, Activity "
			"WHERE Participant.User_Id = User.Id AND Participant.Activity_Id = Activity.Id "
			 "AND Participant.Rating <= 3 AND Activity.Name = '%s'", activity);
		
	mysql_query(conn, query);
	res = mysql_store_result(conn);

while ((row = mysql_fetch_row(res)) != NULL) {
		printf("%s\n", row[0]);
	}
	
	mysql_free_result(res);
	mysql_close(conn);
	
	return 0;
    }
	

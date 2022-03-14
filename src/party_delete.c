#include <dhanda/dhanda.h>
#include <dhanda/party.h>
 #include <unistd.h>




int party_delete(dhanda *app, party *party)
{
	struct party temp;
	int matched = -1;
	int trunc_size, count = 0;

	debug_print("");
	
	
	while(fread(&temp, sizeof(temp), 1, app->party_fp) > 0) {
		if(party->id == temp.id) {
			matched = 0;	
			break;
		}
		count++;
	}
	
	
	while(fread(&temp, sizeof(temp), 1, app->party_fp) > 0) {
		fseek(app->party_fp, sizeof(temp) * -2, SEEK_CUR);
		fwrite(&temp, sizeof(temp), 1, app->party_fp);
		fseek(app->party_fp, sizeof(temp), SEEK_CUR);
		count++;
	}

	fseek(app->party_fp, -sizeof(temp), SEEK_CUR);
	trunc_size = sizeof(temp) * count;
	ftruncate(fileno(app->party_fp), trunc_size);
	
	return matched;
}
			
	
	
	
	
	
	
	
	
	
	
	

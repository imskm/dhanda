#include<dhanda/dhanda.h>
#include<dhanda/party.h>

int party_add(dhanda *app, party *party)
{
      struct party p;
      int new_id;
      

      int cur_pos = 0 , final_pos = 0;

      debug_print("");

      fseek(app->party_fp, 0, SEEK_END);
      if(!ftell(app->party_fp)) {
           new_id = 1; 
      }else{
           fseek(app->party_fp, -sizeof(*party), SEEK_END);
           fread(&p, sizeof(p), 1, app->party_fp);
           new_id = p.id;
           new_id++; 
      }
      party->id = new_id;

      cur_pos = ftell(app->party_fp);
      fwrite(party, sizeof(*party), 1, app->party_fp);
      final_pos = ftell(app->party_fp);

      if(final_pos > cur_pos)
	return 0;
      else
	return -1;
}


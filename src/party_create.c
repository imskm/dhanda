#include<dhanda/dhanda.h>
#include<dhanda/party.h>

int party_add(dhanda *app, party *party)
{
      int cur_pos = 0 , final_pos = 0;

      fseek(app->party_fp, 0, SEEK_END);
      cur_pos = ftell(app->party_fp);
      fwrite(party, sizeof(party), 1, app->party_fp);
      final_pos = ftell(app->party_fp);

      if(final_pos > cur_pos)
	return 0;
      else
	return -1;
}


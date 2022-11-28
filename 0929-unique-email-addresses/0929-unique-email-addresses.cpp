class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
       set<string> emailSet;
        for(auto &email : emails){
            string curEmail = "";
            bool isDomain = false;
            int i =0 ;
            while(i < email.size()){
                if(email[i] == '+' && !isDomain){
                    while(email[i] != '@') i++;
                }
                if(email[i] == '@') isDomain= true;
                if(email[i] != '.' || isDomain)
                    curEmail += email[i];
                i++;
            }
            emailSet.insert(curEmail);
        }
        return emailSet.size();
    }
};
class Solution {
public:
    int minMaxDifference(int num) {
        string first= to_string(num);
        string second=to_string(num);
        int zero = 0;
        int pahila = first.size();
        char yourcharecter=first[zero],mycharecter=first[zero];
        for(int elif=zero; elif<pahila; elif++){
            if(first[elif]!='9'){
                yourcharecter=first[elif];
                break;
            }
        }
        for(int elif=zero; elif<pahila; elif++){
            if(first[elif]==yourcharecter) first[elif]='9';
        }
        for(int elif=zero; elif<first.size(); elif++){
            if(second[elif]==mycharecter) second[elif]='0';
        }
        int bigmax=stoi(first),leastmin=stoi(second);
        return bigmax-leastmin;
    }
};
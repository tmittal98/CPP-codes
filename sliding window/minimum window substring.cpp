 while(j < s.length()){
            
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                
                if(mp[s[j]] <= 0){
                    count--;
                }
            }
            else{
                j++;
                continue;
            }
            if(count == 0){
                    int temp = min_len;
                    min_len = min(min_len,j-i+1);
                if(temp != min_len){
                    start = i;
                    end = j;
                }
                //we will try to optimize our answer
                while(count == 0){
                    if(mp.find(s[i]) == mp.end()){
                        i++;
                    }
                    else{
                        if(mp[s[i]] < 0){
                            mp[s[i]]++;
                            i++;
                        }
                        else if(mp[s[i]] == 0){
                            mp[s[i]]++;
                            i++;
                            count +=1;
                        }
                    }
                }
            }
            
            j++;  
        }
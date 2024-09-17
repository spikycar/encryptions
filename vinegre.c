// encryption and decryption of vinegre
// might be wrong a little bit :|

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// warning, this code allocate a new memory block, please deallocate after use this function.
char * encrypt(char * plaintext, char * key){
    // we do vinegre encryption here
    // caesar encryption is fn(n) = (a + k) % 26 (26 character)
    
    int len_plaintext = strlen(plaintext);
    int len_key = strlen(key);
    char * result = (char *) malloc(len_plaintext*sizeof(char));
    
    if(len_plaintext < len_key){
        return "\0"; // return null pointer if plaintext is somehow smaller than the key
    }
    
    // looping, operate through the whole damn text
    for(int x = 0; x < len_plaintext; x++){
        // assuming there's no space, we can just not check if there's space in it.
        result[x] = ((plaintext[x] + (key[x])) % 26) + 'A'; 
    }
    
    return result;
}

// warning, this code allocate a new memory block, please deallocate after use this function.
char * decrypt(char * chiper, char * key){
    // we do vinegre decryption here
    // caesar decryption is fn(n) = (a - k) % 26 (26 character)
    // the only differences between enc and dec, same with caesar, turn the + to -
    
    int len_chiper = strlen(chiper);
    int len_key = strlen(key);
    char * result = (char *) malloc(len_chiper*sizeof(char));
    
    if(len_chiper < len_key){
        return "\0"; // return null pointer if plaintext is somehow smaller than the key
    }
    
    // looping, operate through the whole damn text
    for(int x = 0; x < len_chiper; x++){
        // assuming there's no space, we can just not check if there's space in it.
        result[x] = ((chiper[x] - (key[x])) % 26) + 'A'; 
    }
    
    return result;
}

int main() {
    char * t1 = "CABIGBALL";
    char *  k = "AAAAAAAAA";
    
    char * res = encrypt(t1, k);
    printf("\nresult is %s, size is %i", res, strlen(res));
    
    char * dec_res = decrypt(res, k);
    printf("\ndecrypted result is %s, size is %i", dec_res, strlen(dec_res));
    
    free(res);
    free(dec_res);
}

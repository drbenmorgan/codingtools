#include <iostream>

#include "curl/curl.h"


void fetch_curl(const char* name) {
  // NB, heed the warnings about not calling curl_global_init/cleanup when
  // more than one thread is running.
  curl_global_init(CURL_GLOBAL_DEFAULT);

  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, name);
    // Follow redirection
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // do it...
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      std::cerr << "curl_easy_perform() failed: "
                << curl_easy_strerror(res)
                << std::endl;
    }
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
}

void fetch(const char* name) {
  // Ultimately, choose method/handler based on protocol...
  fetch_curl(name);
}


int main(int argc, const char *argv[])
{
  fetch(argv[1]);

  return 0;
}

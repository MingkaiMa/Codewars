string encrypt(string text, int rule) {

  string result = "";

  for(int i = 0; i < text.length(); i++){
    char c = (text[i] + rule) % 256;
    result += c;
  }
  return result;
};
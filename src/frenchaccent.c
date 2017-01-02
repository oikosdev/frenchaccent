/*  =========================================================================
    Copyright (c) the Contributors as noted in the AUTHORS file.       
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#include "../include/frenchaccent.h"

int main(int argc, char* argv[]) 
{
 if (argc>2) {
  printf("%s", argv[1]);
  FILE *in = fopen(argv[1], "r");
  fseek(in, 0, SEEK_END);
  long fsize = ftell(in);
  fseek(in, 0, SEEK_SET);  //same as rewind(f);
  char *string = (char*)malloc(fsize + 1);
  assert (fread(string, fsize, 1, in)>0);
  fclose(in);
  string[fsize] = 0;
  char *french;
  textconverter_t *converter = textconverter_new ();
  french = textconverter_convert (converter, "(.+) a (.+)", " \xc3\xa0 ", string); //"test a apportee, test a test again ajoutees et portee. ");
  french = textconverter_convert (converter, "(.+)ee([,s;\\.].+)","\xc3\xa9\x65", french); 
  printf ("Done: %s\n", french);
  FILE *out = fopen(argv[2], "w");
  fprintf (out, "%s", french);
  fclose (out);
  free (french);
  textconverter_destroy (&converter);
 }
 return 0;
}

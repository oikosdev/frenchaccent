/*  =========================================================================
    textconverter - 
        Converts text without accents.
 
        

    Copyright (c) the Contributors as noted in the AUTHORS file.       
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

/*
@header
    textconverter - 
        Converts text without accents.
 
        
@discuss
@end
*/

#include "../include/frenchaccent.h"

//  Structure of our class

struct _textconverter_t {
    int filler;     //  TODO: Declare properties
};


//  --------------------------------------------------------------------------
//  Create a new textconverter.

textconverter_t *
textconverter_new ()
{
    textconverter_t *self = (textconverter_t *) zmalloc (sizeof (textconverter_t));
    assert (self);

    //  TODO: Initialize properties

    return self;
}

//  --------------------------------------------------------------------------
//  Destroy the textconverter.

void
textconverter_destroy (textconverter_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        textconverter_t *self = *self_p;

        //  TODO: Free class properties

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  
char* textconverter_convert(textconverter_t *self, char const *regex, char const *replace, const char *in) {
 assert (self);

 zrex_t *rex = zrex_new (regex);
 char *french;
 const char *after;
 // init: french gets in
 assert (asprintf (&french, "%s", in) > -1);
 // as long as there is a match in french
 while ( zrex_matches (rex, french)) {
  const char* fetch = french;
  zrex_fetch (rex, &fetch, &after, NULL);
  printf ("fetched: %s\n", fetch);
  printf ("after: %s\n", after);
  assert (asprintf (&french, "%s%s%s", fetch, replace, after)>-1);
  printf ("Now = %s\n", fetch);
 }
 printf ("French: %s\n", french);
 return french;
}

//  --------------------------------------------------------------------------
//  Print properties of the textconverter object.

void
textconverter_print (textconverter_t *self)
{
    assert (self);
}


//  --------------------------------------------------------------------------
//  Self test of this class.

void
textconverter_test (bool verbose)
{
    printf (" * textconverter: ");

    //  @selftest
    //  Simple create/destroy test
    textconverter_t *self = textconverter_new ();
    assert (self);
    textconverter_destroy (&self);
    //  @end

    printf ("OK\n");
}

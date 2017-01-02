/*  =========================================================================
    text - 
        Converts text without accents.
 
        

    Copyright (c) the Contributors as noted in the AUTHORS file.       
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

/*
@header
    text - 
        Converts text without accents.
 
        
@discuss
@end
*/

#include "../include/frenchaccent.h"

//  Structure of our class

struct _text_t {
    int filler;     //  TODO: Declare properties
    char *french;
};


//  --------------------------------------------------------------------------
//  Create a new text.

text_t *
text_new (const char *input)
{
    text_t *self = (text_t *) zmalloc (sizeof (text_t));
    assert (self);

    //  TODO: Initialize properties
    assert (input);
    assert (asprintf (&(self->french), "%s", input) > -1);
    return self;
}

//  --------------------------------------------------------------------------
//  Destroy the text.

void
text_destroy (text_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        text_t *self = *self_p;

        //  TODO: Free class properties

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  

char* text_addaccents(text_t *self, char const *regex, char const *replace, const char *in) {
 assert (self);

 zrex_t *rex = zrex_new (regex);
 const char *after;
 // init: french gets in
 assert (asprintf (&(self->french), "%s", self->french) > -1);
 // as long as there is a match in french
 while ( zrex_matches (rex, self->french)) {
  const char* fetch = self->french;
  zrex_fetch (rex, &fetch, &after, NULL);
  printf ("fetched: %s\n", fetch);
  printf ("after: %s\n", after);
  assert (asprintf (&(self->french), "%s%s%s", fetch, replace, after)>-1);
  printf ("Now = %s\n", fetch);
 }
 printf ("French: %s\n", self->french);
 return self->french;
}


//  --------------------------------------------------------------------------
//  Print properties of the text object.

void
text_print (text_t *self)
{
    assert (self);
}


//  --------------------------------------------------------------------------
//  Self test of this class.

void
text_test (bool verbose)
{
    printf (" * text: ");

    //  @selftest
    //  Simple create/destroy test
    text_t *self = text_new ("je suis a la maison");
    assert (self);
    text_destroy (&self);
    //  @end

    printf ("OK\n");
}

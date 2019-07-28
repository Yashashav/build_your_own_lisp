mpc_parser_t* Adjective = mpc_or(4,
    mpc_sym("wow"), mpc_sym("many"),
    mpc_sym("so"), mpc_sym("such")
);

mpc_parser_t* Noun = mpc_or(4,
    mpc_sym("c"), mpc_sym("language"),
    mpc_sym("lisp"), mpc_sym("book"), 
    mpc_sym("build")
);

mpc_parser_t* Phrase = mpr_and(2, strfold, Adjective, Noun, free);

/*  
    TOP-DOWN
    "Doge" language is made up of one or more "Phrases" or it could be empty as well
    "Phrases" are made up of an "Adjective" followed by a "Noun"
    "Adjectives" are made up of
*/



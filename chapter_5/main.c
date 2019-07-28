/*  
    TOP-DOWN explanation
    "Doge" language is made up of one or more "Phrases" or it could be empty as well
    "Phrase" is made up of an "Adjective" followed by a "Noun"
    "Adjective" is made up of "wow", "many", "so", "such"
    "Noun" is made up of "c", "language", "lisp", "book", "build" 
*/

/*
    
*/

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

mpc_parser_t* Doge = mpr_many(mpcf_strfold, Phrase);







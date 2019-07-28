/*  
    TOP-DOWN explanation
    "Doge" language is made up of one or more "Phrases" or it could be empty as well
    "Phrase" is made up of an "Adjective" followed by a "Noun"
    "Adjective" is made up of "wow", "many", "so", "such"
    "Noun" is made up of "c", "language", "lisp", "book", "build" 
*/

/*
    MPC_PARSER_T is struct type which is right now not known to me but I am using it to declare the "type"
    for a parser
    
    MPC_OR is used to create a parser 

    MPC_SYM is to wrap a string 

    MPC_AND is similar to -> 'a' 'b'	First 'a' is required, then 'b' is required.
    i.e for the creation of "Phrase" we require a pre-modifier i.e an "Adjective" followed by a "Noun"

    MPC_MANY is similar to -> 'a'*	Zero or more 'a' are required.
    i.e for the "Doge" language which we have specified, a "Phrase" or zero "Phrase" is required

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







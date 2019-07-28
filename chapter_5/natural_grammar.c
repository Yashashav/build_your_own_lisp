/*
    Writing grammar in so-called natural form
*/

/*
    Using a funciton MPC_NEW a rule can be created and declared.
    Further the re-write rules of the "rules" can be written "naturally" (hence the name)
    Use of MPCA_LANG is used to give the grammar-specification of the rules which are declared previously
*/

/*
    We now create rules by our regular - MPC_PARSER_T type and name them using - MPC_NEW
*/

mpc_parser_t* Adjective = mpc_new("adjective"); //here "adjective" is a rule whose grammar specificaition will be written below
mpc_parser_t* Noun = mpc_new("noun");
mpc_parser_t* Phrase = mpc_new("phrase");
mpc_parser_t* Doge = mpc_new("doge");

/*
    MPCA_LANG is used to define the rules which let us form re-write rules end of the day
*/

mpca_lang(MPCA_LANG_DEFAULT,
    "                                               \
    adjective : \"wow\" | \"many\"                  \
              | \"so\"  | \"such\";                 \
    noun      : \"c\"   | \"language\"              \
              | \"lisp\"| \"book\"                  \
              | \"build\";                          \
    phrase    : <adjcetive> <noun>;                 \
    doge      : <phrase>*;

    ",
    Adjective, Noun, Phrase, Doge);

//Since the grammar-specification is finished we now can parse below

mpc_cleanup(4, Adjective, Noun, Phrase, Doge);
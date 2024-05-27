% Knowledge Base
destination(paris, europe, culture, moderate, spring).
destination(tokyo, asia, culture, expensive, spring).
destination(new_york, north_america, shopping, expensive, autumn).
destination(dubai, middle_east, luxury, expensive, winter).
destination(bangkok, asia, beach, moderate, summer).
destination(rio_de_janeiro, south_america, beach, moderate, summer).
destination(london, europe, culture, moderate, summer).
destination(rome, europe, culture, moderate, spring).
destination(sydney, australia, beach, expensive, summer).
destination(amsterdam, europe, culture, moderate, spring).
destination(hong_kong, asia, shopping, expensive, autumn).
destination(cancun, north_america, beach, moderate, summer).
destination(cairo, africa, culture, cheap, spring).
destination(cape_town, africa, beach, moderate, summer).
destination(mexico_city, north_america, culture, cheap, autumn).
destination(moscow, europe, culture, moderate, winter).
destination(athens, europe, culture, moderate, summer).
destination(istanbul, europe, culture, moderate, spring).
destination(mumbai, asia, culture, cheap, winter).
destination(seoul, asia, culture, moderate, autumn).
destination(bali, asia, beach, moderate, summer).

% Rules
recommend(Destination, Interest, Budget, Weather):-
    destination(Destination, _, Interest, Budget, Weather).

% User Interface
start:-
    write("Welcome to travel"), nl,
    write("Please answer the following questions for recommendation."), nl, 
    ask_budget(Budget),
    ask_interest(Interest),
    ask_weather(Weather),
    findall(Destination, recommend(Destination, Interest, Budget, Weather), Destinations),
    display(Destinations).

ask_budget(Budget):-
    write("What's your budget? "), nl,
    read(Budget).

ask_interest(Interest):-
    write("What's your interest? "), nl,
    read(Interest).

ask_weather(Weather):-
    write("What weather do u like? "), nl,
    read(Weather).

display([]):-
    write("No recommendations"), nl.

display(Destinations) :- 
    write("Recommendations:"), nl,
    display_list(Destinations).

display_list([]).
display_list([H|T]):-
    write("- "), write(H), nl,
    display_list(T).
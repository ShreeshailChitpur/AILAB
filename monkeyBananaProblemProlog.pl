% Initial state
at(monkey, room).
at(chair, room).
at(stick, room).
at(bananas, ceiling).

% Define actions
% Monkey can move from one place to another
move(From, To, Object) :-
    at(Object, From),
    retract(at(Object, From)),
    assert(at(Object, To)).

% Monkey can climb on the chair
climb_on_chair :-
    at(monkey, room),
    at(chair, room),
    move(room, chair, monkey).

% Monkey can grab the stick
grab_stick :-
    at(monkey, room),
    at(stick, room),
    move(room, monkey, stick).

% Monkey can reach the bananas with the stick
reach_bananas :-
    at(monkey, chair),
    at(stick, monkey),
    at(bananas, ceiling).

% Solve the problem
solve :-
    grab_stick,
    climb_on_chair,
    reach_bananas,
    write('Monkey has the bananas!').

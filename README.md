# Flood Rescue

Made for X-NATURE at [HackYeah](https://hackyeah.pl).

## Project description

Our goal was to model the task of flood control.

We have implemented the role of a dispatch officer
coordinating the actions of firefighters in a small city.

The player can control firetrucks and helicopters which deploy barriers limiting and redirecting
water flow.

While our demo is very bare-bones, it does share multiple
characteristics with the real world problem:
- the elements are unforgiving and not fair: humans are at serious disadvantage,
- trying to protect our resources is only a form of damage control and ends up as a net loss,
- even no mistakes on our part can lead to catastrophic results.

The project was inspired by the [Great Flood of 1997](https://en.wikipedia.org/wiki/1997_Central_European_flood).

## Controls
  Space: Pause

  D: Shows coordinates on the map

  ALT: Shows level of tiles

  Arrow keys: Moves vieport

  Mouse wheel: Zoom

  Mouse: Everything else

## Builiding instructions

Install [SFML](https://www.sfml-dev.org/download/sfml/2.4.2/) (>= 2.4.) and
CMake for your system. Run the following commands:

```
cmake
make
```

Now you can run the `Gra` binary in the project root.

## Technologies
C++ & [SFML](https://www.sfml-dev.org/)

## Video
[![video](http://img.youtube.com/vi/oNdM9fLwWtc/0.jpg)](http://www.youtube.com/watch?v=oNdM9fLwWtc "HackYeah - Flood Rescue")


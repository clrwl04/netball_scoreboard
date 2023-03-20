# netball_scoreboard
## Scoreboard for Netball games, capture display score by quarter and whole match

### Runs on Arduino Uno
Requires additional hardware (currently):
- Arduino Uno
- Arduini compatible power supply
- 5 Buttons
- 3 MAX7219 
- 6 4dgit 7segment displays (2 digit 7segment display may give better presentation)

### Working:
Each team score is increased with a button press (button press pulls pin low).
Home team button on **Pin2**
Visitors team button on **Pin4**

### Errors with score can be subtracted:
Home team subtract button **Pin3**
Visitors team subtract button **Pin5**
NOTE: Scores can't go below Zero

Home team scores are on **Max7219 board 0 pos7&8**
Visitors team scores are on **Max7219 board 0 pos4&5**

### Game Quarters:
Game quarters are updated with button press **PinA0** (analogue pin) display **Max7219 board 0 pos1**
When a new quarter is started with button press the current scores for the quarter just ended
are displayed Max7219 boards

#### Quarter 1 (2 digit displays work better for physical display layout)
Home team **Max7219 board 1 pos7&8**
Visitors team **Max7219 board 1 pos5&6**

##### Quarter 2
Home team **Max7219 board 1 pos3&4**
Visitors team **Max7219 board 1 pos1&2**

#### Quarter 3
Home team *Max7219 board 2 pos7&8**
Visitors team *Max7219 board 2 pos5&6**

#### Quarter 4
Home team **Max7219 board 2 pos3&4**
Visitors team **Max7219 board 2 pos1&2**




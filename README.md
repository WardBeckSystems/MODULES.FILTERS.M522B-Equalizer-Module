# M522B Equalizer Module · Filters

Ward-Beck Systems M522B. Wiki page: [M522B on WBSps.ca](https://wardbecksystems.github.io/WBSps.ca/PAGES/M522B.html)

| Folder | What is in it | Files |
|---|---|---|
| [SCHEMATICS/](SCHEMATICS/) | electrical drawings: schematics, functional diagrams, component layouts, wiring | 21 |
| [MECHANICAL/](MECHANICAL/) | front panels, cover plates, metalwork, assemblies; the front panel as vectors | 2 |
| [PINOUTS/](PINOUTS/) | the RTO-144 connector: connection sheets, connector layouts, rear views | 11 |
| [MANUALS/](MANUALS/) | manuals, manual pages, price lists, brochures, documents | 152 |
| [PHOTOS/](PHOTOS/) | photographs of the module | 13 |
| [SOFTWARE/](SOFTWARE/) | program listings, firmware, the plugin | 2 |
| [KICAD/](KICAD/) | KiCad schematics traced from the drawings, the symbol, PCB projects | 7 |
| [OCR/](OCR/) | the note of every file: date, origin, title block, OCR text | 37 |

<!-- module data: tools/module_specs.py, tools/forum_quotes.py -->

**On the WBSps forum (2006|39 - 2014|47):** [3 topics](FORUM.md): what owners and technicians said about it.

## Specifications

From the technical data sheet: [19xx - M522B - M522C Equalizer.pdf](MANUALS/19xx%20-%20M522B%20-%20M522C%20Equalizer.pdf) page 1 (read by OCR; check against the page). As data: [`Specifications.json`](Specifications.json).

| | |
|---|---|
| **Gain** | Unity t/-0.25 dB = |
| **Frequency response** | F/-0.5 aB From 20 Az to 20 KHz With the ecualizer inserted ena cui/boost controls in tne cetent position |
| **Noise** | -90 cBm absolute (20 Hz to 20 KHz) equalizer cut/boost controls in the cetent position |
| **Harmonic distortion** | Less [han 0.10 from 20 Hz:0 20 kHz 3: F20 cBm output level Or less. Less [han 0.0190 at kHz 2[ -20 aBm OUIpui level |
| **Source impedance** | Less than 10 ohms unbalanced. |
| **Input impedance** | Greater than 10k ohms balanced |
| **Input level** | ~6dBm nominal +20 @Bm maximum. |
| **Output impedance** | Less than 50 ohms unbalanced. |
| **Load impedance** | 5k ohms or greater. |
| **Output level** | 26 dBm nominal +20 @Bm maximum. |
| **Channel separation** | Greater than 60 dB = |
| **Phasing** | The low numbered input terminal is In phase with [he output terminal with tne equalizing controls in the detent position |
| **Equalization tracking** | Within 0.5 @B |
| **Power requirements** | -/-25 volts dc (M5228 55 ma, (M522C 80 ma) |
| **Ambient temperature** | Dimensions: to 60 degrees Celsius. 60&quot; wide 7.00&quot; high 6.50&quot; deep (41 Mm 178 Mm 165 Mm/ |
| **Weight** | M5228 M522C IP Ib 0z (0.564 kg nel. 0z (0.624 k9 nela |

## Circuit description

From [19xx - M522B - P15.jpg](MANUALS/19xx%20-%20M522B%20-%20P15.jpg) page 1 (read by OCR; check against the pages). As data: [`CircuitDescription.json`](CircuitDescription.json).

<details><summary>Read it</summary>

**5414-152/5414-1524 FILTER ASSEMBL JES**

The leif: channel section wil be described_ The rignl channe operates an icentica manner and the mono channe makes ue tne left channe circuitry ony Mic Tre quency Stale Variable Filter The Mid-Frequency state variable Filter comprises an inverting buffer amplifier UIA combining amplifier UIB arid Two low Pa;s ters made 4D U2A, U28 C6.C10 and the externa frequency control R6 Tnc external ectcr switch Sw2 affects the overall end [hereny controlling V5 filter g2in The Mter input is applied P1-2 PI-1 and the Filter output appears The Mid-Frequency #2 stale variable filter made uD their asscialed components C17, Cz1 anc externa Determine the center resonant) frequency this filter 03, Ua and control High Frequency High Pass Filter USA buffers the high pass filter network&lt; from the external cut/poost, contro C26 C27, R28 and external frequency contro RSA determine the corner requency the high pass ter USB buffers the ter frequency ceterminins components from the summing amplifier U3B the main equa zer assembly Low Frequency Low Pass Filter The low frequency shelving network comprises external frequency control R5 R30, C29 and C30 Buffer u6 isolates [he frequency determining components from the equalizers summing amplifier

</details>

<!-- /module data -->

## Photos

_Photographs of the module itself: front, back, inside, racked._

<table>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKTEJteG9FMTROVjA/view?resourcekey=0-QpQjaDXoOt7kYmAkwQuxtA" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKTEJteG9FMTROVjA&resourcekey=0-QpQjaDXoOt7kYmAkwQuxtA" width="240" alt="19xx - M522B - wbsps - module - m522b equlizer 001.jpg"></a><br><sub>19xx - M522B - wbsps - module - m522b equlizer 001</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKVVpFeC0tNHdSNkU/view?resourcekey=0-NVWGTkvmnHVeFJ0yZ9TEYA" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKVVpFeC0tNHdSNkU&resourcekey=0-NVWGTkvmnHVeFJ0yZ9TEYA" width="240" alt="19xx - M522B - wbsps - module - m522b equlizer 002.jpg"></a><br><sub>19xx - M522B - wbsps - module - m522b equlizer 002</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKMmotZTB4eE9YMFk/view?resourcekey=0-Y9bWRCqSnqpLNzgMvKxYGg" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKMmotZTB4eE9YMFk&resourcekey=0-Y9bWRCqSnqpLNzgMvKxYGg" width="240" alt="19xx - M522B - wbsps - module - m522b equlizer 003.jpg"></a><br><sub>19xx - M522B - wbsps - module - m522b equlizer 003</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKd0Zqd09uRUdWRHc/view?resourcekey=0-Pi03yxBpjE5GgaGDlU3f4g" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKd0Zqd09uRUdWRHc&resourcekey=0-Pi03yxBpjE5GgaGDlU3f4g" width="240" alt="19xx - M522B - wbsps - module - m522b equlizer 004.jpg"></a><br><sub>19xx - M522B - wbsps - module - m522b equlizer 004</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKNDVJQkNvSXRMNVk/view?resourcekey=0-PrGdnu0Fil2HfPwSx1Braw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKNDVJQkNvSXRMNVk&resourcekey=0-PrGdnu0Fil2HfPwSx1Braw" width="240" alt="19xx - M522B - wbsps - module - m522b equlizer 005.jpg"></a><br><sub>19xx - M522B - wbsps - module - m522b equlizer 005</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKVjg2RFBRZ05ZekU/view?resourcekey=0-FrDDLaheMXB9sGWw5XOlaw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKVjg2RFBRZ05ZekU&resourcekey=0-FrDDLaheMXB9sGWw5XOlaw" width="240" alt="19xx - M522B - wbsps - module - m522b equlizer 006.jpg"></a><br><sub>19xx - M522B - wbsps - module - m522b equlizer 006</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKWDVCQnU2X0V6eTg/view?resourcekey=0-SkwzH6_SjKnjdoEZzoZ2Kw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKWDVCQnU2X0V6eTg&resourcekey=0-SkwzH6_SjKnjdoEZzoZ2Kw" width="240" alt="19xx - M522B - wbsps - module - m522b equlizer 007.jpg"></a><br><sub>19xx - M522B - wbsps - module - m522b equlizer 007</sub></td></tr>
</table>

## Schematics

_Electrical drawings: schematics (-02-), functional diagrams (-01-), component layouts (-06-), wiring (-09-), PCB files (.pcb .dsn), and beside each scan its `(EXTRACTED).svg`: the vectors traced from it._

<table>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKRFhMS0kzOVFva1U/view?resourcekey=0-iru-eFc-A_vl2ZrI3aQliQ" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKRFhMS0kzOVFva1U&resourcekey=0-iru-eFc-A_vl2ZrI3aQliQ" width="240" alt="19xx - M522B - P19 - Filter Schematic.jpg"></a><br><sub>19xx - M522B - P19 - Filter Schematic · <a href="SCHEMATICS/19xx%20-%20M522B%20-%20P19%20-%20Filter%20Schematic%20(EXTRACTED).svg">vectors</a></sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKLTYwRFRzTE9RYlU/view?resourcekey=0-9yJuJzaDh32Rwmc0Fcu99g" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKLTYwRFRzTE9RYlU&resourcekey=0-9yJuJzaDh32Rwmc0Fcu99g" width="240" alt="19xx - M522B - P20 - EQ Schematic.jpg"></a><br><sub>19xx - M522B - P20 - EQ Schematic · <a href="SCHEMATICS/19xx%20-%20M522B%20-%20P20%20-%20EQ%20Schematic%20(EXTRACTED).svg">vectors</a></sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKT3NBRlh5MTlOTDg/view?resourcekey=0-35TtBaz8as-yDxXaTPQcfg" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKT3NBRlh5MTlOTDg&resourcekey=0-35TtBaz8as-yDxXaTPQcfg" width="240" alt="19xx - M522B - P21 - Filter Component Layout.jpg"></a><br><sub>19xx - M522B - P21 - Filter Component Layout · <a href="SCHEMATICS/19xx%20-%20M522B%20-%20P21%20-%20Filter%20Component%20Layout%20(EXTRACTED).svg">vectors</a></sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKNE5TcDJMSVF6ZW8/view?resourcekey=0-zvTSsHCGN8wYSSWEpLNBuQ" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKNE5TcDJMSVF6ZW8&resourcekey=0-zvTSsHCGN8wYSSWEpLNBuQ" width="240" alt="19xx - M522B - P22 - Component Layout.jpg"></a><br><sub>19xx - M522B - P22 - Component Layout · <a href="SCHEMATICS/19xx%20-%20M522B%20-%20P22%20-%20Component%20Layout%20(EXTRACTED).svg">vectors</a></sub></td></tr>
</table>

Not on Google Drive yet: `M522B - P20 - EQ Schematic.jpg`

## Pinouts

_Pinouts: the RTO-144 edge connector (connection sheets, connector layouts and rear views, strapping), and the pinout / connections drawings made from them. The module root `RTO.json` lists every contact._

<table>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKX3RqRnJXRzF5VGM/view?resourcekey=0-ImElcit3UxQFUSQunl-rag" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKX3RqRnJXRzF5VGM&resourcekey=0-ImElcit3UxQFUSQunl-rag" width="240" alt="19xx - M522B - P14 - Pinouts.jpg"></a><br><sub>19xx - M522B - P14 - Pinouts · <a href="PINOUTS/19xx%20-%20M522B%20-%20P14%20-%20Pinouts%20(EXTRACTED).svg">vectors</a></sub></td></tr>
</table>

Not on Google Drive yet: `M522B - RTO-144 Connections.pdf`

## RTO-144 pinout

Read from 2 pinout pictures (each its own `.pinout.json` beside it); the RTO-144 sheet agrees on 7 of 7 contacts. Every contact, with where it was read: [`RTO.json`](RTO.json). How a picture becomes this table: [the pinout decision tree](https://github.com/WardBeckSystems/WBSps.ca/blob/main/2026/Engineering/PINOUTS.md).

| Pin | Signal | Kind | Port | Confidence |
|---|---|---|---|---|
| 1 | N/C | nc |  | high |
| 2 | N/C | nc |  | high |
| 3 | LEFT/MONO INPUT SHIELD | shield | LEFT/MONO INPUT shield | high |
| 4 | LEFT/MONO INPUT + | in | LEFT/MONO INPUT + | high |
| 5 | LEFT/MONO INPUT - | in | LEFT/MONO INPUT - | high |
| 6 | LEFT/MONO OUTPUT | out | LEFT/MONO OUTPUT + | high |
| 7 | LEFT/MONO OUTPUT COMMON | out | LEFT/MONO OUTPUT - | high |
| 8 | RIGHT INPUT SHIELD | shield | RIGHT INPUT shield | high |
| 9 | RIGHT INPUT + | in | RIGHT INPUT + | high |
| 10 | RIGHT INPUT - | in | RIGHT INPUT - | high |
| 11 | RIGHT OUTPUT | out | RIGHT OUTPUT + | high |
| 12 | RIGHT OUTPUT COMMON | out | RIGHT OUTPUT - | high |
| 13 | N/C | nc |  | high |
| 14 | N/C | nc |  | high |
| 15 | N/C | nc |  | high |
| 16 | N/C | nc |  | high |
| 17 | N/C | nc |  | high |
| 18 | N/C | nc |  | high |
| 19 | -25 V | power |  | high |
| 20 | 25 V COMMON | ground |  | high |
| 21 | +25 V | power |  | high |
| 22 | CHASSIS | ground |  | high |

## Manuals and documents

_Manuals and manual pages, price lists, RTO-144 connection sheets, brochures, ads and other document scans._

<table>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKN1JqckhnTXZNbEE/view?resourcekey=0-yq7fhVx6AiSjUotwS8l47w" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKN1JqckhnTXZNbEE&resourcekey=0-yq7fhVx6AiSjUotwS8l47w" width="240" alt="19xx - M522B - M522C Equalizer (2).pdf"></a><br><sub>19xx - M522B - M522C Equalizer (2)</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKNEM1eUtXbEpndzg/view?resourcekey=0-fm-cfa9nxsn83mfimGh5-w" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKNEM1eUtXbEpndzg&resourcekey=0-fm-cfa9nxsn83mfimGh5-w" width="240" alt="19xx - M522B - M522C Equalizer.pdf"></a><br><sub>19xx - M522B - M522C Equalizer</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKZ3l6Z2NXT2ktNUk/view?resourcekey=0-HsHhWpR-zGehbouq6KYoIw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKZ3l6Z2NXT2ktNUk&resourcekey=0-HsHhWpR-zGehbouq6KYoIw" width="240" alt="19xx - M522B - P01.jpg"></a><br><sub>19xx - M522B - P01</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKVzZ1RHlsdXFHdmc/view?resourcekey=0-n_M_wAnYqeNu_ij0fNxHIw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKVzZ1RHlsdXFHdmc&resourcekey=0-n_M_wAnYqeNu_ij0fNxHIw" width="240" alt="19xx - M522B - P02.jpg"></a><br><sub>19xx - M522B - P02</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKdWdQZmxMNi0zMW8/view?resourcekey=0-oJ8bvRII1Qk3CF7Vo5zB_w" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKdWdQZmxMNi0zMW8&resourcekey=0-oJ8bvRII1Qk3CF7Vo5zB_w" width="240" alt="19xx - M522B - P03.jpg"></a><br><sub>19xx - M522B - P03</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKdGlfb3pHUk11Tjg/view?resourcekey=0-uFmcCjH_iYSxbGzoZKP3sg" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKdGlfb3pHUk11Tjg&resourcekey=0-uFmcCjH_iYSxbGzoZKP3sg" width="240" alt="19xx - M522B - P04.jpg"></a><br><sub>19xx - M522B - P04</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKRUdyZ3JHTDNNOWM/view?resourcekey=0-0623F8c5gFfkMCI0uKp_Ug" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKRUdyZ3JHTDNNOWM&resourcekey=0-0623F8c5gFfkMCI0uKp_Ug" width="240" alt="19xx - M522B - P05.jpg"></a><br><sub>19xx - M522B - P05</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKdXRkNnBpSXdsRmc/view?resourcekey=0-akrErjdtnf-3gBcMHF4GwA" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKdXRkNnBpSXdsRmc&resourcekey=0-akrErjdtnf-3gBcMHF4GwA" width="240" alt="19xx - M522B - P06.jpg"></a><br><sub>19xx - M522B - P06</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKTE1aVUdobGplSk0/view?resourcekey=0-Jh60EOKc0Mg8TMvYUoycew" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKTE1aVUdobGplSk0&resourcekey=0-Jh60EOKc0Mg8TMvYUoycew" width="240" alt="19xx - M522B - P07.jpg"></a><br><sub>19xx - M522B - P07</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKbE5neGQ1aGRsS1k/view?resourcekey=0-8uDu02w3NZUo_InoguEDhw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKbE5neGQ1aGRsS1k&resourcekey=0-8uDu02w3NZUo_InoguEDhw" width="240" alt="19xx - M522B - P08.jpg"></a><br><sub>19xx - M522B - P08</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKQWFEellzbjQxX00/view?resourcekey=0-uArR6IGpV9SUHPAf17akrw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKQWFEellzbjQxX00&resourcekey=0-uArR6IGpV9SUHPAf17akrw" width="240" alt="19xx - M522B - P09.jpg"></a><br><sub>19xx - M522B - P09</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKalBsRktQZVZmVkU/view?resourcekey=0-na2YKoI6jEVGu5ueq_SJdg" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKalBsRktQZVZmVkU&resourcekey=0-na2YKoI6jEVGu5ueq_SJdg" width="240" alt="19xx - M522B - P10.jpg"></a><br><sub>19xx - M522B - P10</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKbHRIZHFndTYzdWs/view?resourcekey=0-CaPLUWsPqbCGbRGBD_iMJg" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKbHRIZHFndTYzdWs&resourcekey=0-CaPLUWsPqbCGbRGBD_iMJg" width="240" alt="19xx - M522B - P11.jpg"></a><br><sub>19xx - M522B - P11</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKaHI4UVBiOHZPSE0/view?resourcekey=0-jqEgm25SAL-e00KKJnhzOw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKaHI4UVBiOHZPSE0&resourcekey=0-jqEgm25SAL-e00KKJnhzOw" width="240" alt="19xx - M522B - P12.jpg"></a><br><sub>19xx - M522B - P12</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKMm81V3Q1X1M3NTA/view?resourcekey=0-yyUlbdxUIVYak6bBnbcQ0g" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKMm81V3Q1X1M3NTA&resourcekey=0-yyUlbdxUIVYak6bBnbcQ0g" width="240" alt="19xx - M522B - P13.jpg"></a><br><sub>19xx - M522B - P13</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKZEMyMGNHRXNEcVU/view?resourcekey=0-qBls98D2g049_Sp1Yy6XZQ" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKZEMyMGNHRXNEcVU&resourcekey=0-qBls98D2g049_Sp1Yy6XZQ" width="240" alt="19xx - M522B - P15.jpg"></a><br><sub>19xx - M522B - P15</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKSFlBUl9ZS09DazQ/view?resourcekey=0-I8FDuiFdKoCCwVjh6dPVEA" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKSFlBUl9ZS09DazQ&resourcekey=0-I8FDuiFdKoCCwVjh6dPVEA" width="240" alt="19xx - M522B - P16.jpg"></a><br><sub>19xx - M522B - P16</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKdi1OX1R3LW9rVU0/view?resourcekey=0-VS2ejPVK5V-dK0-e20o6gg" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKdi1OX1R3LW9rVU0&resourcekey=0-VS2ejPVK5V-dK0-e20o6gg" width="240" alt="19xx - M522B - P17.jpg"></a><br><sub>19xx - M522B - P17</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKNlFNaF8tRHktYU0/view?resourcekey=0-9KkRmoJAJ54sCczPlgEjng" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKNlFNaF8tRHktYU0&resourcekey=0-9KkRmoJAJ54sCczPlgEjng" width="240" alt="19xx - M522B - P18.jpg"></a><br><sub>19xx - M522B - P18</sub></td></tr>
</table>

## KiCad

_KiCad: a schematic (`.kicad_sch`) traced from each electrical drawing, the module symbol (`.kicad_sym`) and its PCB projects. Traced schematics are the line work only: redraw with symbols over them._

- [19xx - M522B - M522C Equalizer p19.kicad_sch](KICAD/19xx%20-%20M522B%20-%20M522C%20Equalizer%20p19.kicad_sch)
- [19xx - M522B - M522C Equalizer p20.kicad_sch](KICAD/19xx%20-%20M522B%20-%20M522C%20Equalizer%20p20.kicad_sch)
- [19xx - M522B - P19 - Filter Schematic.kicad_sch](KICAD/19xx%20-%20M522B%20-%20P19%20-%20Filter%20Schematic.kicad_sch)
- [19xx - M522B - P20 - EQ Schematic.kicad_sch](KICAD/19xx%20-%20M522B%20-%20P20%20-%20EQ%20Schematic.kicad_sch)
- [M522B - P20 - EQ Schematic.kicad_sch](KICAD/M522B%20-%20P20%20-%20EQ%20Schematic.kicad_sch)
- [M522B.kicad_sym](KICAD/M522B.kicad_sym)
- [index.html](KICAD/index.html)

## Software

- [cpp](SOFTWARE/cpp)
- [index.html](SOFTWARE/index.html)

---
Archive: Anthony Peter Kuzub · [WBSps.ca](https://WBSps.ca) · [WBSps.Kuzub.com](https://WBSps.Kuzub.com)

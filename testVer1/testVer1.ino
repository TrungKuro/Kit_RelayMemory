//<App !Start!>
// FILE: [testVer1.ino]
// Created by GUIslice Builder version: [0.17.b20]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "testVer1_GSLC.h"

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemToggle2    = NULL;
gslc_tsElemRef* m_pElemToggle2_3  = NULL;
gslc_tsElemRef* m_pElemToggle2_4  = NULL;
gslc_tsElemRef* m_pElemToggle2_5  = NULL;
gslc_tsElemRef* m_pElemToggle2_6  = NULL;
gslc_tsElemRef* m_pElemToggle2_7  = NULL;
gslc_tsElemRef* m_pElemToggle2_8  = NULL;
gslc_tsElemRef* m_pElemToggle2_9  = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch)
{
  if (ch == (char)'\n')
    Serial.println("");
  else
    Serial.write(ch);
  return 0;
}

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void *pvGui, void *pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

  if (eTouch == GSLC_TOUCH_UP_IN)
  {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId)
    {
//<Button Enums !Start!>
    case BTN10_TEA:
      gslc_SetPageCur(&m_gui, PG21);
      break;
    case BTN10_STU:
      gslc_SetPageCur(&m_gui, PG22);
      break;
    case BTN21_OK:
      gslc_SetPageCur(&m_gui, PG31);
      break;
    case BTN21_BAC:
      gslc_SetPageCur(&m_gui, PG10);
      break;
      case BTN21_1:
Serial.println("1");

        break;
      case BTN21_2:
Serial.println("2");

        break;
      case BTN21_3:
Serial.println("3");

        break;
      case BTN21_0:
Serial.println("0");

        break;
      case BTN21_4:
Serial.println("4");

        break;
      case BTN21_7:
Serial.println("7");

        break;
      case BTN21_5:
Serial.println("5");

        break;
      case BTN21_6:
Serial.println("6");

        break;
      case BTN21_8:
Serial.println("8");

        break;
      case BTN21_9:
Serial.println("9");

        break;
    case BTN21_DEL:
      break;
    case BTN31_BAC:
      gslc_SetPageCur(&m_gui, PG10);
      break;
    case BTN31_RES:
      gslc_SetPageCur(&m_gui, PG41);
      break;
    case BTN31_SET:
      gslc_SetPageCur(&m_gui, PG42);
      break;
    case BTN41_BAC:
      gslc_SetPageCur(&m_gui, PG31);
      break;
    case BTN42_BAC:
      gslc_SetPageCur(&m_gui, PG31);
      break;
    case BTN42_SAV:
      gslc_SetPageCur(&m_gui, PG10);
      break;
    case BTN42_RES:
      break;
    case BTN42_ALL:
      break;
    case TOG42_RL1:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2))
      {
        ;
      }
      break;
    case TOG42_RL2:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2_3))
      {
        ;
      }
      break;
    case TOG42_RL3:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2_4))
      {
        ;
      }
      break;
    case TOG42_RL4:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2_5))
      {
        ;
      }
      break;
    case BTN22_SAV:
      gslc_SetPageCur(&m_gui, PG32);
      break;
    case TOG22_RL1:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2_6))
      {
        ;
      }
      break;
    case TOG22_RL2:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2_7))
      {
        ;
      }
      break;
    case TOG22_RL3:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2_8))
      {
        ;
      }
      break;
    case TOG22_RL4:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, m_pElemToggle2_9))
      {
        ;
      }
      break;
    case BTN32_OK:
      gslc_SetPageCur(&m_gui, PG10);
      break;
    case BTN32_BAC:
      gslc_SetPageCur(&m_gui, PG22);
      break;
//<Button Enums !End!>
    default:
      break;
    }
  }
  return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
//<Listbox Callback !Start!>
//<Listbox Callback !End!>

// Scanner drawing callback function
// - This is called when E_ELEM_SCAN is being rendered
bool CbDrawScanner(void *pvGui, void *pvElemRef, gslc_teRedrawType eRedraw)
{
  int nInd;

  // Typecast the parameters to match the GUI and element types
  gslc_tsGui *pGui = (gslc_tsGui *)(pvGui);
  gslc_tsElemRef *pElemRef = (gslc_tsElemRef *)(pvElemRef);
  gslc_tsElem *pElem = gslc_GetElemFromRef(pGui, pElemRef);

  // Create shorthand variables for the origin
  int16_t nX = pElem->rElem.x;
  int16_t nY = pElem->rElem.y;

  // Draw the background
  gslc_tsRect rInside = pElem->rElem;
  rInside = gslc_ExpandRect(rInside, -1, -1);
  gslc_DrawFillRect(pGui, rInside, pElem->colElemFill);

  // Enable localized clipping
  gslc_SetClipRect(pGui, &rInside);

  // TODO - Add your drawing graphic primitives

  // Disable clipping region
  gslc_SetClipRect(pGui, NULL);

  // Draw the frame
  gslc_DrawFrameRect(pGui, pElem->rElem, pElem->colElemFrame);

  // Clear the redraw flag
  gslc_ElemSetRedraw(&m_gui, pElemRef, GSLC_REDRAW_NONE);

  return true;
}
//<Slider Callback !Start!>
//<Slider Callback !End!>
//<Tick Callback !Start!>
//<Tick Callback !End!>

void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(9600);
  // Wait for USB Serial
  // delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

  gslc_InitDebug(&DebugOut);

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();
}

// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{

  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------

  // TODO - Add update code for any text, gauges, or sliders

  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);
}

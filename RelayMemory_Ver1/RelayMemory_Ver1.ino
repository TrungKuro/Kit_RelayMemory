//<App !Start!>
// FILE: [RelayMemory_Ver1.ino]
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
#include "RelayMemory_Ver1_GSLC.h"
#include "Pin_Connect.h"

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef *box41Stu1 = NULL;
gslc_tsElemRef *box41Stu2 = NULL;
gslc_tsElemRef *box41Stu3 = NULL;
gslc_tsElemRef *box41Stu4 = NULL;
gslc_tsElemRef *box41Tea1 = NULL;
gslc_tsElemRef *box41Tea2 = NULL;
gslc_tsElemRef *box41Tea3 = NULL;
gslc_tsElemRef *box41Tea4 = NULL;
gslc_tsElemRef *btn10Stu = NULL;
gslc_tsElemRef *btn31Res = NULL;
gslc_tsElemRef *tog22R1 = NULL;
gslc_tsElemRef *tog22R2 = NULL;
gslc_tsElemRef *tog22R3 = NULL;
gslc_tsElemRef *tog22R4 = NULL;
gslc_tsElemRef *tog42R1 = NULL;
gslc_tsElemRef *tog42R2 = NULL;
gslc_tsElemRef *tog42R3 = NULL;
gslc_tsElemRef *tog42R4 = NULL;
gslc_tsElemRef *txt21Pas = NULL;
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

/* ------------------------------------------------------------------------- */
/*                                    MORE                                   */
/* ------------------------------------------------------------------------- */

String pass = "";
char dotPass[LENGTH_PASS];

void processedPass(String btn)
{
  byte length = pass.length();
  if (btn == "<")
  {
    if (length > 0)
    {
      pass.remove(length - 1);
      dotPass[length - 1] = ' ';
    }
  }
  else
  {
    if (pass.length() < LENGTH_PASS)
    {
      pass = pass + btn;
      dotPass[length] = '*';
    }
  }
  gslc_ElemSetTxtStr(&m_gui, txt21Pas, dotPass);
  //
  DEBUG_PRINT("PW: ");
  DEBUG_PRINTLN(pass);
}

/* ------------------------------------------------------------------------- */

/**
 * True:  Enable Button
 * False: Disable Button
 */
bool enableBtnStudent = false; // Monitor 1.0
bool enableBtnResult = true;   // Monitor 3.1

bool relayTeacher[NUMBER_RELAY] = {ON_RELAY, ON_RELAY, ON_RELAY, ON_RELAY};
bool relayStudent[NUMBER_RELAY] = {ON_RELAY, ON_RELAY, ON_RELAY, ON_RELAY};

void showResult()
{
  gslc_ElemSetCol(&m_gui, box41Tea1, GSLC_COL_WHITE, (relayTeacher[INDEX_R1]) ? (COLOR_ON) : (COLOR_OFF), GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui, box41Stu1, GSLC_COL_WHITE, (relayStudent[INDEX_R1]) ? (COLOR_ON) : (COLOR_OFF), GSLC_COL_WHITE);
  //
  gslc_ElemSetCol(&m_gui, box41Tea2, GSLC_COL_WHITE, (relayTeacher[INDEX_R2]) ? (COLOR_ON) : (COLOR_OFF), GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui, box41Stu2, GSLC_COL_WHITE, (relayStudent[INDEX_R2]) ? (COLOR_ON) : (COLOR_OFF), GSLC_COL_WHITE);
  //
  gslc_ElemSetCol(&m_gui, box41Tea3, GSLC_COL_WHITE, (relayTeacher[INDEX_R3]) ? (COLOR_ON) : (COLOR_OFF), GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui, box41Stu3, GSLC_COL_WHITE, (relayStudent[INDEX_R3]) ? (COLOR_ON) : (COLOR_OFF), GSLC_COL_WHITE);
  //
  gslc_ElemSetCol(&m_gui, box41Tea4, GSLC_COL_WHITE, (relayTeacher[INDEX_R4]) ? (COLOR_ON) : (COLOR_OFF), GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui, box41Stu4, GSLC_COL_WHITE, (relayStudent[INDEX_R4]) ? (COLOR_ON) : (COLOR_OFF), GSLC_COL_WHITE);
}

/* ------------------------------------------------------------------------- */

void IOexpanderWrite(byte address, byte data)
{
  Wire.beginTransmission(address);
  Wire.write(data);
  Wire.endTransmission();
}

/* ------------------------------------------------------------------------- */

void showSetPan()
{
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R1, relayTeacher[INDEX_R1]);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R2, relayTeacher[INDEX_R2]);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R3, relayTeacher[INDEX_R3]);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R4, relayTeacher[INDEX_R4]);
}

void resetSetPan()
{
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R1, ON_RELAY);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R2, ON_RELAY);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R3, ON_RELAY);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R4, ON_RELAY);
  //
  DEBUG_PRINTLN("Reset SetPan");
}

void allSetPan()
{
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R1, OFF_RELAY);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R2, OFF_RELAY);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R3, OFF_RELAY);
  gslc_ElemXTogglebtnSetState(&m_gui, tog42R4, OFF_RELAY);
  //
  DEBUG_PRINTLN("All SetPan");
}

void saveSetPan()
{
  /**
   * Step1: Kích hoạt tất cả Relay về ON (Red)
   * Step2: Lưu "relayTeacher"
   * Step3: Đặt "relayStudent" về ON (Red)
   * Step4: Bật "enableBtnStudent"
   * Step5: Tắt "enableBtnResult"
   */
  IOexpanderWrite(IO_EXPAND_ADDR, ON_ALL_RELAY);
  delay(RELAY_TRIG_TIME);
  IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
  //
  relayTeacher[INDEX_R1] = gslc_ElemXTogglebtnGetState(&m_gui, tog42R1);
  relayTeacher[INDEX_R2] = gslc_ElemXTogglebtnGetState(&m_gui, tog42R2);
  relayTeacher[INDEX_R3] = gslc_ElemXTogglebtnGetState(&m_gui, tog42R3);
  relayTeacher[INDEX_R4] = gslc_ElemXTogglebtnGetState(&m_gui, tog42R4);
  //
  relayStudent[INDEX_R1] = ON_RELAY;
  relayStudent[INDEX_R2] = ON_RELAY;
  relayStudent[INDEX_R3] = ON_RELAY;
  relayStudent[INDEX_R4] = ON_RELAY;
  //
  enableBtnStudent = true;
  gslc_ElemSetCol(&m_gui, btn10Stu, BTN_ENA_FRA, BTN_ENA_FIL, BTN_ENA_SEL);
  //
  enableBtnResult = false;
  gslc_ElemSetCol(&m_gui, btn31Res, BTN_DIS_FRA, BTN_DIS_FIL, BTN_DIS_SEL);
}

/* ------------------------------------------------------------------------- */

void setExam()
{
  gslc_ElemXTogglebtnSetState(&m_gui, tog22R1, relayStudent[INDEX_R1]);
  gslc_ElemXTogglebtnSetState(&m_gui, tog22R2, relayStudent[INDEX_R2]);
  gslc_ElemXTogglebtnSetState(&m_gui, tog22R3, relayStudent[INDEX_R3]);
  gslc_ElemXTogglebtnSetState(&m_gui, tog22R4, relayStudent[INDEX_R4]);
}

void saveExam()
{
  /**
   * Step1: Lưu "relayStudent"
   * Step2: Tắt "enableBtnStudent"
   * Step3: Bật "enableBtnResult"
   */
  relayStudent[INDEX_R1] = gslc_ElemXTogglebtnGetState(&m_gui, tog22R1);
  relayStudent[INDEX_R2] = gslc_ElemXTogglebtnGetState(&m_gui, tog22R2);
  relayStudent[INDEX_R3] = gslc_ElemXTogglebtnGetState(&m_gui, tog22R3);
  relayStudent[INDEX_R4] = gslc_ElemXTogglebtnGetState(&m_gui, tog22R4);
  //
  enableBtnStudent = false;
  gslc_ElemSetCol(&m_gui, btn10Stu, BTN_DIS_FRA, BTN_DIS_FIL, BTN_DIS_SEL);
  //
  enableBtnResult = true;
  gslc_ElemSetCol(&m_gui, btn31Res, BTN_ENA_FRA, BTN_ENA_FIL, BTN_ENA_SEL);
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
      pass = "";
      memset(dotPass, 0, LENGTH_PASS);
      gslc_ElemSetTxtStr(&m_gui, txt21Pas, dotPass);
      gslc_SetPageCur(&m_gui, PG21);
      break;
    case BTN10_STU:
      if (enableBtnStudent)
      {
        setExam();
        gslc_SetPageCur(&m_gui, PG22);
      }
      break;
    case BTN21_OK:
      if (pass == PASS)
      {
        gslc_SetPageCur(&m_gui, PG31);
        //
        DEBUG_PRINTLN("Valid Pass");
      }
      else
      {
        pass = "";
        memset(dotPass, 0, LENGTH_PASS);
        gslc_ElemSetTxtStr(&m_gui, txt21Pas, dotPass);
        //
        DEBUG_PRINTLN("Wrong Pass!");
      }
      break;
    case BTN21_BAC:
      gslc_SetPageCur(&m_gui, PG10);
      break;
    case BTN21_1:
      processedPass("1");
      break;
    case BTN21_2:
      processedPass("2");
      break;
    case BTN21_3:
      processedPass("3");
      break;
    case BTN21_0:
      processedPass("0");
      break;
    case BTN21_4:
      processedPass("4");
      break;
    case BTN21_7:
      processedPass("7");
      break;
    case BTN21_5:
      processedPass("5");
      break;
    case BTN21_6:
      processedPass("6");
      break;
    case BTN21_8:
      processedPass("8");
      break;
    case BTN21_9:
      processedPass("9");
      break;
    case BTN21_DEL:
      processedPass("<");
      break;
    case BTN31_BAC:
      gslc_SetPageCur(&m_gui, PG10);
      break;
    case BTN31_RES:
      if (enableBtnResult)
      {
        showResult();
        gslc_SetPageCur(&m_gui, PG41);
      }
      break;
    case BTN31_SET:
      showSetPan();
      gslc_SetPageCur(&m_gui, PG42);
      break;
    case BTN41_BAC:
      gslc_SetPageCur(&m_gui, PG31);
      break;
    case BTN42_BAC:
      gslc_SetPageCur(&m_gui, PG31);
      break;
    case BTN42_SAV:
      saveSetPan();
      gslc_SetPageCur(&m_gui, PG10);
      break;
    case BTN42_RES:
      resetSetPan();
      break;
    case BTN42_ALL:
      allSetPan();
      break;
    case TOG42_RL1:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, tog42R1))
      {
        //
        DEBUG_PRINTLN("TeaRL1 ON");
      }
      else
      {
        //
        DEBUG_PRINTLN("TeaRL1 OFF");
      }
      break;
    case TOG42_RL2:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, tog42R2))
      {
        //
        DEBUG_PRINTLN("TeaRL2 ON");
      }
      else
      {
        //
        DEBUG_PRINTLN("TeaRL2 OFF");
      }
      break;
    case TOG42_RL3:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, tog42R3))
      {
        //
        DEBUG_PRINTLN("TeaRL3 ON");
      }
      else
      {
        //
        DEBUG_PRINTLN("TeaRL3 OFF");
      }
      break;
    case TOG42_RL4:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, tog42R4))
      {
        //
        DEBUG_PRINTLN("TeaRL4 ON");
      }
      else
      {
        //
        DEBUG_PRINTLN("TeaRL4 OFF");
      }
      break;
    case BTN22_SAV:
      gslc_SetPageCur(&m_gui, PG32);
      break;
    case TOG22_RL1:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, tog22R1))
      {
        IOexpanderWrite(IO_EXPAND_ADDR, ON_RL1);
        delay(RELAY_TRIG_TIME);
        IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
        //
        DEBUG_PRINTLN("StuRL1 ON");
      }
      else
      {
        IOexpanderWrite(IO_EXPAND_ADDR, OFF_RL1);
        delay(RELAY_TRIG_TIME);
        IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
        //
        DEBUG_PRINTLN("StuRL1 OFF");
      }
      break;
    case TOG22_RL2:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, tog22R2))
      {
        IOexpanderWrite(IO_EXPAND_ADDR, ON_RL2);
        delay(RELAY_TRIG_TIME);
        IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
        //
        DEBUG_PRINTLN("StuRL2 ON");
      }
      else
      {
        IOexpanderWrite(IO_EXPAND_ADDR, OFF_RL2);
        delay(RELAY_TRIG_TIME);
        IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
        //
        DEBUG_PRINTLN("StuRL2 OFF");
      }
      break;
    case TOG22_RL3:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, tog22R3))
      {
        IOexpanderWrite(IO_EXPAND_ADDR, ON_RL3);
        delay(RELAY_TRIG_TIME);
        IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
        //
        DEBUG_PRINTLN("StuRL3 ON");
      }
      else
      {
        IOexpanderWrite(IO_EXPAND_ADDR, OFF_RL3);
        delay(RELAY_TRIG_TIME);
        IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
        //
        DEBUG_PRINTLN("StuRL3 OFF");
      }
      break;
    case TOG22_RL4:
      // TODO Add code for Toggle button ON/OFF state
      if (gslc_ElemXTogglebtnGetState(&m_gui, tog22R4))
      {
        IOexpanderWrite(IO_EXPAND_ADDR, ON_RL4);
        delay(RELAY_TRIG_TIME);
        IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
        //
        DEBUG_PRINTLN("StuRL4 ON");
      }
      else
      {
        IOexpanderWrite(IO_EXPAND_ADDR, OFF_RL4);
        delay(RELAY_TRIG_TIME);
        IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);
        //
        DEBUG_PRINTLN("StuRL4 OFF");
      }
      break;
    case BTN32_OK:
      saveExam();
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
  // Serial.begin(9600);
  // Wait for USB Serial
  // delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

  /* To use I2C */
  Wire.begin();
  IOexpanderWrite(IO_EXPAND_ADDR, NORMAL_STATE_OF_RELAY);

  /* To use the Debug feature */
  DEBUG_BEGIN(115200);

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

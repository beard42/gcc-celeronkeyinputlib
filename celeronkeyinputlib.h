#ifndef CELERON_KEYINPUTLIB_H
#define CELERON_KEYINPUTLIB_H

//---------------------------------------------------------------------------
//
// ��������� ����������
//
//---------------------------------------------------------------------------


// ��������� ����������� (������� ��������������� ���������� ����� � �����):
//    (����������: ������ ��������� ������������ � ��������� keyScanInput_SystickHandler, ������������ ����� �������������� ������ ��������� ������.)
//    ������� "������� �������" �����������, ��� ������� ������ � ��������� - ��� ���������� ���������� "���������� �������" ����������������� RC-����...
//    ���������� ����� ��������: ������ ������ ������������ ����������, � �������, ��� �������, LatchDepth �����������, ����� ��������������� ��������� �� ��������� (������� �� "�������" � "����������", ��� ��������).
//    ���������� �������� �������� = [1..128]
//    ������������: ������ ������ �������� ���� �������� ������� ��������, ����� ����� �������� �������� "���������� �������" �� �������, ��� �������� ����, ��� ������� ������ ��� ������� �������� ���������� ������������� ������.
//    �����������: ����� ��������� ������� "���������� �������" � ����������� ������ �� ����� (�� ������, ���� �� �������� ������� ���������� ����������������� RC-������� �� ����� �������?) - ������� ���������� �������� ��������������� "�������" � ������� (LatchDepth=1). �����������: �� � ����, � �� ���������������� - �� ���������������� ������ ���� ������, � ����� �������!
#define CButtonLatchDepth   1     /* ������� ������� �����������, ��� ������ �������� ������ = ���������� ������ ������, � ������� ������� ������ ������ ���������� ������ "1", ����� ����������� "�������" ��� "0", ����� ����������� "����������". */

//    ������������: ��� ���������, ������� ������� ����������� ������ ���� ������ ���������, ��������� �� ������ ��������� �� ������� ������������ ������� �� ���� ���/�����/���, ��� 24 ����� �� ������! ��� �������� �����, � ������� ����������� ������� ����������� �������...
//    ������ �����������: ����� ��������� ��������� ��������� ����� keyScanInput_SystickHandler (�� ������, ���� �� ������������� �������� ������� keyScanInput_EXTIHandler) - �� ��������� �������� ��������� CEncoderLatchDepth, � ������ ��������������� ������ ����������������. �����������: ��� �������� ������ ��� ��������� (��������� ������ ��� ������ ���������).
//#define CEncoderLatchDepth  2     /* ������� ������� �����������, ��� ������ ���������� ����� ��������... � �����, �� ��, ��� � ��� ������� �������� ������, �� ��� �������� - "������� �������" ������� �������� � �� ������� ������! ��������� �������� �������� ����� ��������� � ���������������, � ����� ����, ������� ������������� ������� ����, ��� �������� ������. */



// ������� ������� ����������� keyScanInput_SystickHandler (� ������)
// �������: 
//    ����� ������ � ���������� 1��   - ������������� ������� 1000 ��. (�������������)
//    ����� ������ � ���������� 10��  - ������������� �������  100 ��. (���������, ���� ���������� ��������)
//    ����� ������ � ���������� 100�� - ������������� �������   10 ��. (�� ������������� �� ������������ ���������� ����������, ������� �������� ������� �� ������)
#define CButtonSystickFrequency  1000

// ������� ������������� ������� (� ������), � ������� ������������ "������� ������� ���������" � ������-�������� ������.
//    ����������: ������� 5-������� "�������� ������� ���������" = 31 ���������� �������. �� ����������� ����� - ������� �� ������� �������������!
//    ������������ ����������� ����������� �����, � �������� = (2^5-1)/CButtonTimeIncFrequency.
//    ��������: ��� �������=2 ��, ����������� ����� ��������� �� 15,5 ���... � ��� �������=4 ��, ����������� ����� �� 7,75 ���.
#define CButtonTimeIncFrequency  5

// ��������� ������ "������� ���������" (� ���������� �������� ��������), �� ���������� �������� ��� ������ ��� ����������� ������-��� "BSC_LongHold".
//    (����������: ������ ��������� ������������ � ��������� keyIncreaseTimeForAllButtons.)
//    ����, ������� ������������ ����� ��������� ������ (���������� ������ ���������� ������ �������: �� 1/CButtonTimeIncFrequency ���), �� ���������� �������� ��� ����������� ������-��� "ShortHold", � ����� ��� ����� - ��� ��������� "LongHold"...
//    ��������: ����� "LongHold" �������� ��� 1.5 ��� � ����, ������� ������ �������� (1.5 ���)/(1/CButtonTimeIncFrequency) = (1.5 ���)*CButtonTimeIncFrequency.
#define CButtonLongHoldDuration  ((uint8_t)((CButtonTimeIncFrequency)*(1.0)))



// �������� ������� "Smart Button" (������� ���� ������ ��������) (����� ��������� - ���������������)
//    ��������� �����������, ��������, ������: ��� ����� �������� "������/������" ������������ ������������ ��������� ���������� ���������� ���������: 
//    "������������ ����� ������ � ���������� � ����� ��������� �����, �������� �������� ������������� �������� +1, +1,... � ����� ��������� �����, �������� �������� ������� +5, +5,..."
//#define SMART_BUTTON_ENABLE

// ��������� ��������� ��������� ������ (��� �������� �������� � ������ ����������������� - �������� �� ������� ����� ������������) (����� ��������� - ����������������)
#define NO_ENCODERS_AT_ALL



//---------------------------------------------------------------------------
//
// ��������������� �������
//
//---------------------------------------------------------------------------



// ���������: ���� ������-������� STATUS ������ ������-��� == VALUE ?
// ���: ���������� �������� ������-���� VALUE = BSC_NotPressed, BSC_ShortHold, BSC_LongHold, BSC_ShortPress, BSC_LongPress (�������� ���� BUTTON_STATUS_CODE)...
//
//�������������� ������, ����������� � �������� ��������� ��������� ������� ������:
#define BUTTON_REGISTER_HAVE_STATUS( STATUS, VALUE )    (((STATUS)&(0x07<<BUTTON_STATUS_CODE)) == ((VALUE)<<BUTTON_STATUS_CODE))
//���������� ������, ����������� � �������� ��������� ������������� ������:
#define BUTTON_HAVE_STATUS( ID, VALUE )                 BUTTON_REGISTER_HAVE_STATUS( keyButtonList[(ID)].Status, VALUE )



// ���������: ���� � ������-�������� STATUS ���������� ���� & FLAG ?
// ���: ���������� �������� ����� FLAG = BUTTON_IS_HOLDDOWN, BUTTON_IS_PRESSED, BUTTON_HOLDEN_LONG (�.�. ��������� ������������ ����������� ���� BUTTON_STATUS_CODE)...
// ����������� ����������:
//    ������ ������ ����� ��������� ������ ����� �������� BUTTON_HAVE_STATUS, ��� ������������ ��������� ������������ ������-����. ������, �� ������������ ��� �������� "������������ �� � ������ ������ ������?" (� �� ����� ������� �������):
//      ����� �������, ��������, ������ ���������� ���� ���������:  if(BUTTON_HAVE_STATUS(BSC_ShortHold) || BUTTON_HAVE_STATUS(BSC_LongHold))... ���������� ������:  if(BUTTON_HAVE_FLAG(BUTTON_IS_HOLDDOWN))...
//      ����������, � ��� ������������ ����� ������������ ������� �������+����������, ��� ����������� �� ���� ������� ������ ������������:  if(BUTTON_HAVE_STATUS(BSC_ShortPress) || BUTTON_HAVE_STATUS(BSC_LongPress))... ���������� �� ����:  if(BUTTON_HAVE_FLAG(BUTTON_IS_PRESSED))...
//    ������, � ���� ������� �������� �������� "�������" �� "���������� �����"! ����� �������, "����������" ������ ������������ - ��� ���, ������ ������ ������ ���������� FALSE.
//
//�������������� ������, ����������� � �������� ��������� ��������� ������� ������:
#define BUTTON_REGISTER_HAVE_FLAG( STATUS, FLAG )       (((STATUS)!=(RESET_BUTTON_STATUS)) && ((STATUS)&(1<<(FLAG))))
//���������� ������, ����������� � �������� ��������� ������������� ������:
#define BUTTON_HAVE_FLAG( ID, FLAG )                    BUTTON_REGISTER_HAVE_FLAG( keyButtonList[(ID)].Status, FLAG )



// ���������: � ������� ������ ������� ������������ ������? ������, ������������ (��� ������������) �� ������ "�������" � ������� TIME ����������� ��� ������ ?
// ���: 
//    TIME ����������� � ��, ��� �������� ������������� ����������, � ����� ��������� ������������ �������� � ���������� ����.
//    ���������� �������� ��������� TIME = [1*CButtonSystickFrequency/CButtonTimeIncFrequency .. (2^5-1)*CButtonSystickFrequency/CButtonTimeIncFrequency]  (������������ �� ��������� ����������� ���� BUTTON_HOLDING_TIME).
//      �� ������� �������, ��� � ������-�������� ����� ������������ ���������, � �������� CButtonTimeIncFrequency (� � �������� ������ - ����� �� ����������������)!
//      ��� ������, ��� ���������� TIME=0 ��� ������ - �.�. ���� ���� ������ ������ �� ����������, �� ���������, ��� ���������� "������������ �� 0 ��� ������ ��"...
//      � �����, ����� ������ �������� ������ (TIME < CButtonSystickFrequency/CButtonTimeIncFrequency) �������������� � TIME=0.
// ����������� ����������:
//    ������ ������ ������� ������������ � ������ � �������� �������� �������� ��������� ������: 
//      if(BUTTON_HAVE_STATUS(������������ ��� ������) && BUTTON_HAVE_TIME(��� �����-�� �����))...
//      if(BUTTON_HAVE_FLAG(������������ ��� ������)   && BUTTON_HAVE_TIME(��� �����-�� �����))...
//      ��� �������, ��������� ���� ��������� ������ �����, �� "����� ����" �� ������? ����� ��������� � ������ ������? ��� ����� ������� ������ ������������ �����-��?..
//      � ���� ����������� ������� ������� ���, ����� ����������� �� ������� � ���������� ������ �������, ����� ������� ���������� - ������� ��� ������ �������� �������� �������� ��������� ������.
//    �����, � ���� ������� �������� �������� "�������" �� "���������� �����"! ����� �������, "����������" ������ ������������ - ��� ���, ������ ������ ������ ����� ���������� FALSE.
//
//�������������� ������, ����������� � �������� ��������� ��������� ������� ������:
#define BUTTON_REGISTER_HAVE_TIME( STATUS, TIME )       (((STATUS)!=(RESET_BUTTON_STATUS)) && (((STATUS)&(0x1F<<BUTTON_HOLDING_TIME)) >= (((CButtonTimeIncFrequency)*(TIME)/(CButtonSystickFrequency))<<BUTTON_HOLDING_TIME)))
//���������� ������, ����������� � �������� ��������� ������������� ������:
#define BUTTON_HAVE_TIME( ID, TIME )                    BUTTON_REGISTER_HAVE_TIME( keyButtonList[(ID)].Status, TIME )



// ����������� ������ ������ � ��������� "���������� �����".
//    ���������� ������� �������������� ������� "���������� �����" ��������� ��������� ��� ������ ������������� �������� �������. (��� ��� ���������� "������� ��������� �������" ��� ������������ ����������...)
//    ��������, ������ �� ������ ��������� ����������� ������� �� �������. �����, ������������ ������ ��������� ������. � ������ ��� ��������� ������� ������ - ������� �������� ��������� ���������� �������...
// ����������� ����������:
//    ���������� �� ���������� ��������� ������� ���������� � �������.
//    ��������� ������� ������ ����� ������� ������������� (������������������ � �������� ���������), ��� ������ ���������� ������ ����� ��������.
#define BUTTON_RESET( ID )                              (keyButtonList[(ID)].Status = RESET_BUTTON_STATUS)



// ��������� "���������� �����" ����� ������ �����������: ��� ����������� ��� ������ �� ��� ���, ���� ���������� ������ �� ����� ��������. � �����, ��� ���������� ������, ������-������� ������ ������������ � ���� �������������.
// ������ ������ ������������ �������� �������� �������� � ������-��������, � ��������� "���������� �����" - ��� ���� ����������� � �������.
// ��� ��� ����� ������ ��������� ��������� ���� ������, �� ��������, �������� ������������ ������...
//
// ���������������������� ������ BUTTON_HOLDDOWN_OR_RESET ����������� �� ������� "������ ������������" ��� "������ ��������".
//    (����������: ������ ������ �������� ������������ �������������� ���� BUTTON_HAVE_FLAG. ������� � ���, ��� � ����� ��������� ��������� �������� "�������" �� "���������� �����". � �����, �� ���� ������, ���� ������ ��������� ������ �� "���������" ������.)
//    ����� �������, ������ ������ ����� ���������� TRUE - ��� �� ��� "������������", �� ��� ������������ � "����������" ������. 
//    ��, � ��� �� ���������� ������������ ������ - ���� ��������� (������ TRUE), ��� �����.
//
// �������� ��������:
//    ������, ��� ������� ������ ����� ��������� �������� �������: ���� ������� - ���� ���������, ����� �����, � ���������� �� ���������� ���������� ������...
//    �� �����������, ���� ������ "����������� ���������": ���� ������ ������������, ������ ������ ������������� �����... ��� ����� ������ - ������, ������ �� ����������� �����, � ���������� �������� ������ �� ���� BUTTON_IS_HOLDDOWN...
//    �� ������ ������: ����� ����� ������ �������� � ��� ����������� (� ������� �������), � ��� ����������� ��������� ������ (����� ������ ������������ �� ������������)!
//    � ��������� ������, ���� ������: ����� ������ ���������� ��� �����������, �� ���������, �...
//      ���� �� �������� � ������, �� ��� ������������� � ������ BUTTON_IS_PRESSED, �� ������� ����� ����� ������������� ������ �����������!
//      ����� ����, ������������� ������, � ������� ���� ������������� ������ ������, � ��� ������ ������ ������� �������� ����������� � �������, ��� "��������� �������", �� ������� ����� ������������ ��� ���� ������ ������������!
// �������:
//    ��� � ����� �������, ������� ������ ���������� ������� �� ������� � ��������� BUTTON_HOLDDOWN_OR_RESET, � � ����������� ���������� ������� ���� �������� ������!
//
// ������:
//    �����, � ����� ���������� ���� ������ ��� ������: ������1="������� ����� �����" � ������2="������� ����� ������".
//    ��� ���������� ��������������� ������ - ����� ���������������. �.�. ���������� ������ ��������� ������ ������� �������� �� ������� BUTTON_IS_HOLDDOWN, � � ����������� �� ���������� ������-�������...
//    �� ���, ��������, ��������� ����������������� ��� ������ �������: "�������� � ��������� ���������" - ��� ����� ����������� ��� ������������� ��������� ����� ������. 
//    ������, ����� �������� �������� ������ ��� ���������� ������ ������� �� ���� ������: ����� ������ ������ ������������, ��� ������, ��� �������� �����-������!
// ����� ���:
//
//    while(1) 
//    {
//      static ��������=0;
//
//      if(BUTTON_HOLDDOWN_OR_RESET(������1) && BUTTON_HOLDDOWN_OR_RESET(������2))
//      { //���� ���������� ����� ���������� �����������, ���� ������ ��� ������, �� ������ �� ����� �� ��������
//        ���������(��������*2);
//        BUTTON_RESET(������1);    //������������� �������� ������� ��� ���������� ������...
//        BUTTON_RESET(������2);
//      }
//
//      if(BUTTON_HAVE_FLAG(������1, BUTTON_IS_HOLDDOWN))
//      { //���� ���������� ���������� ����������, ����� ������ ������� ������
//        �������� = +1;
//        ���������(��������);
//      }
//
//      if(BUTTON_HAVE_FLAG(������2, BUTTON_IS_HOLDDOWN))
//      { //���� ���������� ���������� ����������, ����� ������ ������� ������
//        �������� = -1;
//        ���������(��������);
//      }
//    }
//
//�������������� ������, ����������� � �������� ��������� ��������� ������� ������:
#define BUTTON_REGISTER_HOLDDOWN_OR_RESET( STATUS )     ((STATUS)&(1<<(BUTTON_IS_HOLDDOWN)))
//���������� ������, ����������� � �������� ��������� ������������� ������:
#define BUTTON_HOLDDOWN_OR_RESET( ID )                  BUTTON_REGISTER_HOLDDOWN_OR_RESET( keyButtonList[(ID)].Status )



//---------------------------



// �������� ���������� �����, ����������� � "������� ��������" ��������
#define ENCODER_COUNTER( ID )              (keyEncoderList[(ID)].Counter)


// �������� "������� �������" �������� (������� ��������� �� ���������� ��������� ������� ���������� � ���������)
#define ENCODER_RESET( ID )                (ENCODER_COUNTER(ID) = 0)



//---------------------------



// ����������� ������ � �������
#define DECLARE_BUTTON(PORT_, PIN_) {  \
    /* .Channel.Port = */ PORT_,       \
    /* .Channel.Pin  = */ PIN_,        \
    /* .Integrator   = */ 0,           \
    /* .Status       = */ 0}



// ����������� �������� � �������
#define DECLARE_ENCODER(PORT1,PIN1, PORT2,PIN2) {  \
    /* .Channel1.Port = */ PORT1,                  \
    /* .Channel1.Pin  = */ PIN1,                   \
    /* .Integrator1   = */ 0,                      \
    /* .Channel2.Port = */ PORT2,                  \
    /* .Channel2.Pin  = */ PIN2,                   \
    /* .Integrator2   = */ 0,                      \
    /* .Status        = */ 0,                      \
    /* .Counter       = */ 0}



// ����������� ��������������� ��������: ��������� ���������� ��������� � �������.
// ��. ������� �� "������������� ��"... http://ru-wiki.org/wiki/%D0%9F%D1%80%D0%B5%D0%BF%D1%80%D0%BE%D1%86%D0%B5%D1%81%D1%81%D0%BE%D1%80_%D0%A1%D0%B8
#define NUMBER_OF_ARRAY_ITEMS( array ) ( sizeof( array ) / sizeof( *(array) ) )




//---------------------------------------------------------------------------
//
// ����������� �����
//
//---------------------------------------------------------------------------
// ������������, ������ ���������: ��� ������� ���� ������ ������ ����� ������ 1 ���� - 
// ����� �� 8-������ ����������������� ���������� ���� "thread-safe" (���������� ��������� ������ � ������).


//---------------------------
// ������� �����
//---------------------------

// ����������� ���� ��� ������, ����������� "������� �����" 
// ����������: � ������ ���������� - ��� ����� ����, �� ������� ����� ������... �� ������������, ����� ���������� ��� (����� keyScanInput) � ��� ������ ����������: ����� ������������ �������, ����� ���, ��� ��.
typedef struct {
  volatile unsigned char* Port;  // ���� = (PORTA, PORTB,...)
  unsigned char  Pin;            // ��� = [0..7]
} TInputChannel;



//---------------------------
// ������� �����������
//---------------------------

// ����������� ���� ��� �������� "����������"
typedef volatile int8_t TInputIntegrator;     // �������: int8_t = signed char

// ����������� ��������� �������� "����������"
#define INTEGRATOR_IS_PRESSED   7   /* ���� "������������ ��������� ������" (�� �� Negative Flag "N"), ��������: ="0" (������ ��������) ��� ="1" (������ ������). */



//---------------------------
// �������� ������ ������
//---------------------------

// ����������� ���� ��� �������� "������ ������"
typedef volatile uint8_t TButtonStatus;

// ����������� ���� ��� �������� �������
typedef volatile uint8_t TButtonSmartTimer;


// ����������� ��������� �������� "������ ������"
#define BUTTON_HOLDING_TIME   0    /* ���� �����   [4:0] = ������� ���������� ���������� ������ ������� (�� 1/CButtonTimeIncFrequency ���), � ������� ������� ������ ��������(����/����) "�������". */
#define BUTTON_STATUS_CODE    5    /* � ��� ����� [7:5] = ���������� �������� "������-��� ������" (��. ���� ���������������� ��������). */
#define BUTTON_HOLDEN_LONG    5    /* ���� "������������ ��������� ������": 0-�������� ��� 1-�������. */
#define BUTTON_IS_PRESSED     6    /* ���� "������������� ����������� ������� ������": "0" - ������ �� ����������, "1" - ���� �������. */
#define BUTTON_IS_HOLDDOWN    7    /* ���� "������ ������������ � ������� ���������": "0" - ������ ������ "��������", "1" - ������ ������ "������ � ������������". */


// ��������� �������� ���� BUTTON_STATUS_CODE           (�������, ��� �������� ����������� ���������������� "������" � �������� - ������ 4 ��������):
#define BSC_NotPressed        0    /*  0b000 = "�� ������"          (�������� ��������� ��� ���� ������ - ������ ������ ����� "������") */
#define BSC_ShortHold         4    /*  0b100 = "�������� ���������" (������ ������, � �� ��� ������������, ���� "��������" �����) */
#define BSC_LongHold          5    /*  0b101 = "������� ���������"  (������ ������, � �� ��� ������������, ��� "����������" �����) */
#define BSC_ShortPress        2    /*  0b010 = "�������� �������"   (������ ���� ������, � ����� ��������, � ����� � ��������� ���� "��������������") */
#define BSC_LongPress         3    /*  0b011 = "������� �������"    (������ ���� ������, � ����� ��������, � ����� � ��������� ���� "����������") */
#define BSC_ResetStatus       7    /*  0b111 = "���������� �����"   (������ ��������� � ����.��������� "���������� �����") */
// ����������: �����, ������� "BSC_" �������� "Button Status Codes"...


// ��� "���������� �����" (0b11111111), ������� ������� ��������� ������-�������� ������, �� ���������� ��������� ���������� � ��� �������  (��� ������ ������-�������� � ��������� ��������� � ���������� ����������� �� ����� �������)
#define RESET_BUTTON_STATUS   0xFF



// ������ ����������� ���������� ������
typedef struct {
  TInputChannel      Channel;
  TInputIntegrator   Integrator;
  TButtonStatus      Status;        // ������� "������ ������"
#ifdef SMART_BUTTON_ENABLE
  TButtonSmartTimer  SmartTimer;    // ������� �������, ���������� � ������� ���������� ������������ "������ �������" (������������ � �������� CButtonTimeIncFrequency)
#endif
} TButtonData;



//---------------------------
// �������� ������ ��������
//---------------------------

// ����������� ���� ��� �������� "������ ��������"
// ����������: ������-������� ��������, ��������, ������� �� ������������ ���������� �����!
typedef volatile uint8_t TEncoderStatus;

// ����������� ���� ��� �������� "������� �����"  
// ������ ��������: ������ ����������� ��������� �� ��������. ��� ������ �������� ����� �����: Signed Int = [-128..127]
typedef volatile int8_t TEncoderCounter;     // �������: int8_t = signed char


// ����������� ��������� �������� "������ ��������" (������ �� ����, ����)
#define ENCODER_STATUS_X1           0    /* ����������        ��������� ��������: �������� �������� ������ AC(X1) */
#define ENCODER_STATUS_Y1           1    /* ����������        ��������� ��������: �������� �������� ������ BC(Y1) */
#define ENCODER_STATUS_PRECOUNTER   2    /* ��������� ��� ���� - ��� ��������������� ������� =1..4, ����� ������� "�� 4 ������������ ������� �������� �� ���� ���" ������������� � ������������ ����� �����, �������������� � �������� "�������� �����" ��������... */
#define ENCODER_STATUS_X2           4    /* ���������/������� ��������� ��������: �������� �������� ������ AC(X2) */
#define ENCODER_STATUS_Y2           5    /* ���������/������� ��������� ��������: �������� �������� ������ BC(Y2) */
#define ENCODER_STATUS_F2           7    /* ���������/������� ��������� ��������: ����������� ����������� �������� (F2) - ��� ����� ������, �������� ��������� ����������: � ����� ������� ���������� ��������� ��� ��������? */
// ���������:
// 	F = 0	C.W., 	�������� �� ������� ("������ ����")	(+1) � ��������
// 	F = 1	C.C.W.,	�������� ������ ������� ("����� ����")	(-1) � ��������
// 	��������� ������� ������� X,Y (=0 ��� 1), �����, � ��������, �� ����� - ������������ ���� ������� �� ������������...



// ������ ����������� ���������� �������
typedef struct {
  TInputChannel    Channel1;
  TInputIntegrator Integrator1;
  TInputChannel    Channel2;
  TInputIntegrator Integrator2;
  TEncoderStatus   Status;        // ������� "������ ��������" (�������� ���������� ����� �� ������������!)
  TEncoderCounter  Counter;       // ������� "������� �����"
} TEncoderData;




//---------------------------------------------------------------------------
//
// ���������� ������
//
//---------------------------------------------------------------------------


// ��������� ���� ������������ ������
extern TButtonData   keyButtonList[];
extern uint8_t       keyButtonListCount;


// ��������� ���� ������������ ���������
extern TEncoderData  keyEncoderList[];
extern uint8_t       keyEncoderListCount;


// �������������� ������ (���������� ����� � ��������� keyButtonList):
#define BUTTON_RIGHT    0 
#define BUTTON_CENTER   1
#define BUTTON_LEFT     2
// ��������� ������� � ���������� ������ ������ (��� ���������� ����������: ���� ���� - ���� ������, ���������� � ����� "0" ��� � ������� "1")
#define BUTTON_STATE    0

// �������������� ��������� (���������� ����� � ��������� keyEncoderList):
#define ENCODER_SPEED   0    /* ����������: ������, ������� ������ ����������� �� ��������������! */




//---------------------------------------------------------------------------
//
// ��������� �������
//
//---------------------------------------------------------------------------


//-------------------------------------
// ����������� �����������
//-------------------------------------

// �������� ��������� ������� �������� ���������: ��� ������ � ���������.
// �� ����� ������� ��������� � ���������� ���������� SysTick_Handler()...
void keyScanInput_SystickHandler(void);

// �������� ��������� ������� �������� ���������: ������ ��� ���������, �������������� ����� (�������).
// �� ����� ������� ��������� � ���������� ���������� EXTI_IRQHandler()...
// ��������� ���������� �����: ��� ����� ������� ��������, ����������� ����� � ������� GPIO_EXTI, �������� ����������, ����� "on Rising/Falling edge"...
// �����: ���� �� ����������� ����� ����� keyScanInput_SystickHandler, �� ����� �� ���� ����������, ����������� ��������������� ����������� ��������� CEncoderLatchDepth! ����� ������������� ���������� ��������� ��������� � ����������� keyScanInput_SystickHandler...
void keyScanInput_EXTIHandler(void);



//-------------------------------------
// ���������� ������
//-------------------------------------

// ��������������� ������ ��������� �������� ������:
void keyResetStatusForAllButtons(void);
uint8_t keyIfAnyButtonUnhandled(void);
uint8_t keyIfAnyButtonHolddown(void);
uint8_t keyIfSmartButtonPressed(uint8_t ID, uint8_t WaitingScheme);

// ��� �������� ������������� (obsolete)
#define keyIfAnyButtonPressed keyIfAnyButtonUnhandled



#endif  // CELERON_KEYINPUTLIB_H

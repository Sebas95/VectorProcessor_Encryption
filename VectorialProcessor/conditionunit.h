#ifndef CONDITIONUNIT_H
#define CONDITIONUNIT_H


class ConditionUnit
{

private:
    bool Z;
public:
    ConditionUnit();
    void eval_conditions(bool* WE,bool* we_s, bool* we_v, bool* cond);
    void write_flags(bool z,bool instr_en);
};

#endif // CONDITIONUNIT_H

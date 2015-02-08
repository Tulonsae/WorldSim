In progress - turn this into real documentation.

For GenderType, there is a significant difference between GENDER_UNDEFINED
and GENDER_UNKNOWN.  GENDER_UNDEFINED means that the gender has not been
assigned or determined.  GENDER_UNKNOWN means that a determination has been
made, but that the gender is unknown.  This difference is maintained so that
a process could sweep through all persons with GENDER_UNDEFINED and make an
assignment of gender, but keep specified persons with an unknown gender.

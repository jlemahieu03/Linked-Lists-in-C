// jdh CS3010 Fall 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "movie.jlemahie.h"
#include "list.jlemahie.h"

//--------------------------------------------------------------------------

bool findTest(char *testname, ListNode *theList, Movie *searchFor, Movie *expMovie) {
  Movie *m;
  bool fail;

  fail = false;
  m = findItem(theList, searchFor, (ComparisonFunction) compareByTitle);
  if (expMovie == NULL) {
    if (m != NULL) {
      printf("%s: bad result from find; expected result == NULL for finding '%s'\n", testname, searchFor->title);
      fail = true;
    }
  } else {
    if (m == NULL) {
      printf("%s: bad result from find; expected result != NULL for finding '%s'\n", testname, searchFor->title);
      fail = true;
    } else {
      if (strcmp(m->title, expMovie->title)) {
        printf("%s: bad result from find; expected title='%s' got '%s'\n", testname, expMovie->title, m->title);
        fail = true;
      }
      if (m->audience != expMovie->audience) {
        printf("%s: bad result from find; expected audience='%d' got '%d'\n", testname, expMovie->audience, m->audience);
        fail = true;
      }
      if (m->critics != expMovie->critics) {
        printf("%s: bad result from find; expected critics='%d' got '%d'\n", testname, expMovie->critics, m->critics);
        fail = true;
      }
    }
  }

  return fail;
} // findTest()

//---------------------------------------------------------------

int listTests() {
  ListNode *theList = NULL;
  Movie barbieMovie, tenetMovie, contagionMovie, bigShortMovie;
  Movie dummyMovie;
  Movie laConfidentialMovie, stepBrothersMovie;
  Movie stingMovie, bourneIdentityMovie, mindingtheGapMovie;
  int rc, numfails, idx, fail;

  numfails = 0;

  initializeMovie(&dummyMovie, "Dummy Title", 2023, 83, 88);

  initializeMovie(&barbieMovie, "Barbie", 2023, 83, 88);
  rc = insertItem(&theList, &barbieMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  initializeMovie(&tenetMovie, "Tenet", 2020, 76, 69);
  rc = insertItem(&theList, &tenetMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  initializeMovie(&contagionMovie, "Contagion", 2011, 63, 85);
  rc = insertItem(&theList, &contagionMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  initializeMovie(&bigShortMovie, "The Big Short", 2015, 88, 89);
  rc = insertItem(&theList, &bigShortMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  initializeMovie(&stepBrothersMovie, "Step Brothers", 2008, 69, 55);
  rc = insertItem(&theList, &stepBrothersMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  initializeMovie(&laConfidentialMovie, "LA Confidential", 1997, 94, 99);
  rc = insertItem(&theList, &laConfidentialMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  printList(theList, (PrintFunction) printMovie);

  printf("--------------------------------------------------\n");

  rc = findTest("T1", theList, &tenetMovie, &tenetMovie);
  if (rc != 0)
    ++numfails;

  rc = findTest("T2", theList, &dummyMovie, NULL);
  if (rc != 0)
    ++numfails;

  rc = findTest("T3", theList, &contagionMovie, &contagionMovie);
  if (rc != 0)
    ++numfails;

  rc = findTest("T4", theList, &laConfidentialMovie, &laConfidentialMovie);
  if (rc != 0)
    ++numfails;

  printf("--------------------------------------------------\n");

  initializeMovie(&stingMovie, "The Sting", 1973, 95, 93);
  rc = insertItem(&theList, &stingMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  initializeMovie(&bourneIdentityMovie, "The Bourne Identity", 2002, 93, 84);
  rc = insertItem(&theList, &bourneIdentityMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  initializeMovie(&mindingtheGapMovie, "Minding the Gap", 2018, 91, 100);
  rc = insertItem(&theList, &mindingtheGapMovie, (ComparisonFunction) compareByAudience);
  if (rc != 0) {
    printf("ERROR: expected rc = 0 from insertItem(); got %d\n", rc);
    ++numfails;
  }

  printList(theList, (PrintFunction) printMovie);

  printf("--------------------------------------------------\n");

  Movie *expectedList[] = {&contagionMovie, &stepBrothersMovie, &tenetMovie, &barbieMovie, &bigShortMovie, &mindingtheGapMovie, &bourneIdentityMovie, &laConfidentialMovie, &stingMovie};
  int numItems = sizeof(expectedList) / sizeof(Movie *);

  char *notInList = "not in list";
  Movie *m = removeItem(&theList, notInList, (ComparisonFunction) compareByTitle);
  if (m != NULL) {
    printf("%s fail: expected rc == NULL from removeItem('%s')\n", "T5", notInList);
    ++numfails;
  }

  idx = 0;
  fail = 0;
  while ( ! fail && idx < numItems ) {
    Movie *m = removeItem(&theList, expectedList[idx]->title, (ComparisonFunction) compareByTitle);
    if (m == NULL) {
      printf("%s fail: expected rc != NULL from removeItem('%s')\n", "T6", expectedList[idx]->title);
      ++numfails;
      fail = 1;
    }
    idx = idx + 1;
  }

  // list should be NULL now
  if (theList != NULL) {
    printf("%s fail: expected list to be NULL\n", "T7");
    printf("instead, here's the list:\n");
    printList(theList, (PrintFunction) printMovie);
    ++numfails;
  }

  if (numfails == 0)
    printf("SUCCESS! All tests pass.\n");
  else
    printf("Fail: %d test(s) did not pass\n", numfails);

  return numfails;
}

//--------------------------------------------------------------------------

int main() {
  listTests();
}

#include "../../includes/som.h"

void       			clear_list(t_iris_database *iris_data)
{
    t_best_match_unit   *tmp;
    t_best_match_unit   *bmu = iris_data->best_match_unit_head;

	while (bmu->next != NULL)
	{
		tmp = bmu->next;
		free(bmu);
		bmu = tmp;
	}
}

void      random_bmu(t_iris_database *iris_data)
{
  if (iris_data->bmu_activated > 1)
  {
    int			index;
    int			i;
    t_best_match_unit   *tmp;
    t_best_match_unit   *bmu = iris_data->best_match_unit_head;

    srand(time(NULL));
    i = 0;
    index = rand() % iris_data->bmu_activated;
    while (i < index)
    {
      tmp = bmu->next;
      bmu = tmp;
      i++;
    }
    iris_data->best_match_unit = bmu;
  }
}
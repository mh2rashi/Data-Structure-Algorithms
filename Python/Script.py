import pandas as pd
import time
start_time = time.time()

df = pd.read_excel("Mort_CD_AL_F1_2__B1.xlsx")
list_of_indices = df[df['Row'] == -2].index.to_numpy().tolist() # this will get us a list of row indices where there's -2, which
# signifies the beginning of a table.
num_of_rows = df.shape[0]
list_of_indices.append(num_of_rows)

table_names = df['TableName'].unique().tolist()
total_num_of_files = len(table_names)

for file_num in range(total_num_of_files):
    start_index = list_of_indices[0]
    end_index = list_of_indices[1]

    master_version = df.iloc[start_index:end_index]
    master_version_name = table_names[0] + ".xlsx"

    # construct file_names
    file_names = list()
    for i in range(18, 71):
        file_name = table_names[0] + "_" + str(i)
        file_names.append(file_name)

    # 1st version from columns 1 (inclusive)-26(exclusive)
    list_of_dfs = list()
    start_col_index = 25
    last_col_num_outer = 20
    col_names = df.columns.values.tolist()
    first_col = col_names[0]
    for i in range(53):
        start_col = col_names[start_col_index]
        col_names_subset = [col_names[i] for i in range(start_col_index)]
        subset_df = master_version[col_names_subset]
        subset_df['TableName'] = file_names[i]
        last_col_num = last_col_num_outer
        while last_col_num <= 100:
            data = [last_col_num-1]
            data.extend(subset_df['C'+str(last_col_num-1)].to_list()[2:])

            data_len = len(data)
            # in the following case, we have to fill in the missing values.
            if data_len < num_of_rows:
                delta = num_of_rows - data_len
                fill_remaining_vals = [1000] * delta
                data.extend(fill_remaining_vals)
            subset_df['C' + str(last_col_num)] = data
            last_col_num += 1
        list_of_dfs.append(subset_df)
        start_col_index += 1
        last_col_num_outer += 1

    # SANITY CHECK: Size of file_names and list_of_df's should be equal.
    with pd.ExcelWriter(master_version_name) as writer:
        master_version.to_excel(writer, sheet_name=master_version_name)
        for i in range(53):
            list_of_dfs[i].to_excel(writer, sheet_name=file_names[i])

print('It took', time.time()-start_time, 'seconds.')


